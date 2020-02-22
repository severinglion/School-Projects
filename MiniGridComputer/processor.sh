#!/bin/sh

# set permissions to be private
umask 077

# ensure that the program was called correctly
if [ $# != 1 ]; then
    echo "$0 usage error!" >&2
    echo "usage: $0 <processor_id>" >&2
    exit -1
fi

# global variables
id=$1
input=""
infile="/tmp/processor-${USER}-fifo${id}"
outfile="/tmp/processor-${USER}.log.${id}"

# print a timestamp to the log file
timestamp () {
    msg="<<<<: "$outfile" "$(date)": >>>>"
    echo $msg >> $outfile
}

# remove the fifo before exiting the program
cleanup () {
    rm -f $infile
}
trap cleanup PIPE EXIT

# if the fifo doesn't exist then create it
if [ ! -p ${infile} ]; then
    mkfifo $infile
fi

# put a timestamp on the log file to indicate it's been touched
timestamp
echo "Processor ${id} starting up" >> $outfile

# main process loop
while read input < $infile
do
    if [ "$input" != '' ]; then
        # check for shutdown conditions
        if [ "$input" = 'exit' ]; then
            break;
        fi
        {
            #run the command in a sandbox
            timestamp
            $(eval ${input} >> $outfile 2>&1)
        }
    fi

done