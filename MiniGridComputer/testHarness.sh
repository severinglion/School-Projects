#!/bin/sh

FIFO_S="/tmp/server-${USER}-fifo"
FIFO_P="/tmp/processor-${USER}-fifo"
PROC_LOG="/tmp/processor-${USER}.log."
cpu_count=$(grep -c processor /proc/cpuinfo)
test_comm="ls -la"

cleanup () {
    kill $server_pid > /dev/null 2>&1
}

trap cleanup INT TERM HUP EXIT

echo "Cleaning out any residual logs"
rm -f /tmp/processor-$USER.log.*

# spawn the server daemon in the background
echo "Starting up mgServer"
./mgServer > test/server_output 2>&1 & #redirect output to file for later examinations
server_pid=$!
sleep 2
# test cases
############

### test basic usage that the correct processor is doing the job correctly 
## basic input (compare expected command output with normal command output)

expected_file="test/case1.expected"
output_file="test/case1.output"
$($test_comm > $expected_file)

proc_arr=$( seq 0 $(( $cpu_count - 1 )) )
echo -n "Testing case 1 (round robin job allocation via fifo interface): ... "
conclusion="success"
for i in $proc_arr 
do 
    echo $test_comm > $FIFO_P$i
    sleep 1 # give the processes time to work
    tail -c $(wc -c < ${expected_file}) $PROC_LOG$i > $output_file
    if ! diff $expected_file $output_file > test/case1.difference.$i; then
        conclusion="failure"
    fi
done
echo $conclusion

### testing round robin job allocation using the socket interface
test_comm="ls -la | grep mg"
expected_file="test/case2.expected"
output_file="test/case2.output"
$( eval "$test_com" > $expected_file)
echo -n "Testing case 2 (round robin job allocation via socket interface): ... "
conclusion="success"
for i in $proc_arr
do 
    if ps -p $server_pid > /dev/null; then 
        ./mgSubmitJob ${test_comm}
        sleep 1
        tail -c $(wc -c < ${expected_file}) $PROC_LOG$i > $output_file
        if ! diff $expected_file $output_file > test/case1.difference.$i; then
            conclusion="failure"
        fi
    else
        echo "Fatal Error: mgServer is no longer running"
        exit 1
    fi
done
echo $conclusion




