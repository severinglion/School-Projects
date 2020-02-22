# Game Programming - Assignment 1 
**CIS 4820 - University of Guelph**  
**Joshua Bunt**           

--------------------------------------------------------------

## Compliation and Run steps
-----------------------------
  Extract the tar file into a directory and `cd` into the extracted directory. Included below are
  steps to run on MacOS and Linux. Native windows is unsupported; however, there is a work around for this.
  Check the [Run on Windows](#run-on-windows) section.  

#### MacOS 

```bash
make -f makefile.macos
./build/game.out
```

#### Linux

```bash
make
./build/game.out
``` 

## Design decisions
----------------------
  - for some variation in the ground colour I only have valleys covered with
  grass some of the time (depending on a random number)

  - the clouds all move in the same direction in the top 10 or so cubes
    - clouds are 3d boxes, some coloured white others grey chosen at random

  - generated hills can interesect with other generated hills to allow
  some variateion in shape

  - valleys can interesect with only other valleys for variation in shape

  - bases are just boxes right now just tall enough to clear the highest hills

  - clouds run at different speeds are updated at max once per second

  - clouds loop around the sky, as it exits one point in the sky it enters at
  the other end

  - chose to write the assignment in C++ so that I could use OOP paradigms
    - used inheritance to allow a game object to be updated by the game engine

## Known Issues
------------------
  - when moving the viewpoint towards a corner the viewpoint enters part of the
  cube before stopping

  - when moving the viewpoint along the edge of some cubes, the viewpoint may
  enter the cube depending on the angle the viewpoint is.

  - during compilation on macos, several depcrecation warnings appear even
  with the -Wno-depcrecation-declaration flag


## Run on Windows
------------------

IMPORTANT NOTE: None of these instructions come with any sort of a guarantee. If you follow
them and they end up causing any problems for you or your computer then it is entirely your responsibility.
If your hard disk is wiped clean... it's your problem.
If all of your assignments are deleted... it's your problem.
If your computer stops working... it's your problem.

If you are unsure of your ability to follow these instructions or to recover from any
problems that might arise then you should not do any of the things listed on this page.
If you do follow any of these instruction then make sure to BACKUP ALL OF
THE IMPORTANT INFORMATION ON YOUR LAPTOP BEFORE YOU TRY ANY OF THESE INSTRUCTION.


### 1. Installing the Linux Kernel on Windows 10
--------------------------------------------

The instructions to install a Linux kernel on Windows 10 are on the page [here](https://docs.microsoft.com/en-us/windows/wsl/install-win10). Follow all of the instructions to install the kernel on this page.

Next, follow the link to the "Initializing a newly installed distro" page and
follow all of those instructions.

I used Ubuntu 18.04 LTS and it seemed to work well..


### 2. Installing the Development Tools
-----------------------------------
You will need to install the compiler and libraries that are necessary for
development and to use OpenGL. The libraries I used are:

```bash
sudo apt install gcc
sudo apt install ubuntu-desktop
sudo apt install make
sudo apt-get install mesa-utils
sudo apt-get install freeglut3
sudo apt-get install freeglut3-dev
```


### 3. Install an X-server on Windows
---------------------------------
You will need to run a X-server on Windows that will display the output from the OpenGL
program. You can find one named VcXsrv [here](https://sourceforge.net/projects/vcxsrv/).

Download, install, and run this program.


### 4. Set the Display
------------------

I included a script to automate this last part. If you wish to use it enter the following into the terminal:

```bash
chmod +x setWSLVars.sh
. setWSLVars.sh
```

If you prefer doing things manually, then on the command line run the following:

```bash
export DISPLAY=localhost:0
```

You can put this in the shell startup file so it is executed every time you start a
terminal window. This will save you from having to type it each time you open a terminal
window.

You can test if the installation works by running:
```bash
glxgears
```
on the command line. If it works then the gears should move quickly. If the gears
move very slowly then the display is probably not connected to the X-server. 
You can try to close the Linux terminal window and the VcXsrv

(The instructions for using OpenGL on Linux are originally from this [page](https://github.com/microsoft/WSL/issues/2855 ).)

Now you can build as if you are on [Linux](#linux).



