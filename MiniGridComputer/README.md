# Assignment 4: Mini Grid Computer

CIS 3050: Systems Programming  
University of Guelph  
Joshua Bunt

----------------------------------------------------------

## Overview
The mini grid computer is composed of the scripts mgServer, mgSocketInterface, mgSubmitjob and processor.  

## How to configure mini grid system
From the project's root folder enter the following commands:

```shell
chmod +x bin/config  
./bin/config  
```

## Known Limitations
* Currently the system is limited to the size of a fifo buffer, once an overflow happens the pipe is broken and the system will crash. To restart, manually you could clear out the tmp folder with all files that contain `$USER`, or more easily run the `mgServer` command twice. It will crash the first time, but it's cleanup code will ensure that the second call will work fine.

* Socket size is hard coded at 1024 bytes, a standard buffer size.

* All scripts written for this assignment reference other scripts as `./` thus, to run the server you need to be at the root of the assignment folder. I could add the assignment root folder to the PATH variable in the config file, but then you'd have to run the config file every time you accessed it via a new terminal.

* In my testing, I noticed that when the test harness kills the mgServer script, for some reason the mgSocketInterface daemon never gets killed, even though there is a signal handler that is supposed to kill it. A definitive bug that I didn't have time to fix. 

* Due to time restraints I could not cover more test cases. Also, my second test cases, which tests both socket interface and piping commands seemed to have been fatally flawed in some way. Normal command line piping is broken in my implementation but the socket interface worked with testing I did outside of the test harness. 


## Utilities
There are several scripts included to speed up certain tasks, the scripts and how/what they do are listed below. Note: for these scipts to work they need to be run from the assignment's root directory.  
 * the config script adds execution priviledge to required scripts


## Testing
This section will describe how to use the test harness and the results. A test harness has been included to help quickly test how well the system works. To run the test harness navigate to the assignment root folder and simply copy the command below.

```shell
./testHarness
```

### Test Cases

1. Test Round Robin job allocation using the fifo interface  
**Test Using**  
This test is test case 1 in the test harness. To run see the instructions above.  
**What is the expected output**  
The test harness uses a pass fail determination of whether a test failed. The expected outcome should show test 1 as succeded. The test case itself is testing the output of the ls -la command on the assignment root folder and test it against what each processor stores in the log file. If the output is the same for all cores then the test has passed. Otherwise there was either an issue with allocating a job to the right core or an issue with how the core executed the job. If the test failed, the differences can be viewed in the .difference files in the test folder.  
**Did the test pass?**  
This test passed on linux and mac; however, a few times during testing it seemed to have failed but pass directly after a retest (without changing anything). This is most likely a bug in the test harness.  

2. Test Round Robin job allocation using socket interface  
**Test Using**  
This is test case 2 in the test harness. To run the harness, follow the instructions above.  
**What is the expected output**  
The test harness will show success or failure depending on if the test passed. The test is checking in a similar fashion to the fifo interface. It will use the `ls -la | grep mg` command through a socket and check the corresponding log file for the processor that should have gotten the job. If the actual output for any of the processors are different than the expected the test will fail. This test also checks that ordinary piping is achieved correctly.   
**Did the test pass?**  
This test failed on mac and linux. Piping did not output properly and the socket interface seemed to break during automation; however, in interactive use it worked fine. This could be a bug with ether the test harness or the server or both. 
