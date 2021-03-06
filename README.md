# School Projects  

A collection of notable school projects I have worked on. Please note that this is not an exhuastive list,
as over the last several years I have completed many projects. Instead of dumping all of them into a portfolio
I have opted to pick a few of my favourites. I do not guarantee their usefullness because they were intended to make me
learn a specific aspect of programming or theory. Each project is unique enough where I believe my skills are showcased.  


If you would like to see more of my work, just email [me](mailto:bunt.joshua@gmail.com).  

## Projects Contained  

1. **Mini Grid Computer**  

    This is an assignment I completed for my systems programming class. It simulates a distributive computational model
    in which a job, or process, could be loaded onto a server, completed and the output sent back. Part of the
    assignment was to create a number of daemons, equal to that of the number of cpu cores on the system, to perform a
    job that was served to them. A seperate server was used to recieve input from a terminal. The input could be sent by
    two interfaces: a named pipe interface and a socket based interface. Because part of the course emphasized the
    challenges in creating a platform agnostic programs, this was programmed to run on both Linux and MacOS.
    Unfortunately, supporting Windows wasn't included as a requirement for this assignment.

    This assignment was written using shell scripting, and Python. The daemon job handler and server were written using
    shell scripts, while the socket interface was written in Python. While I have not had much exposure to Python, part
    of the assignment was getting familiar enough to implement a socket interface for the server.

    Please note that there was starter code provided, and I will include that in a zip file within the project root
    folder so that one can easily see which portions I have actually written. I have also included a readme file to
    cover design decisions and limitations/bugs that are present.

2. **Game Programming - A1**  

    This assignment is the foundation for the game programming project, a class I am currently enrolled in.
    It includes the starter code written by the instructor in c. The game is envisioned to be a Minecraft style RTS
    game. For A1 we are required to procedurally generate the level terrain so that it can include hills and valley's,
    two bases, some animated clouds and basic view point collision detection.

    The starter code was written in C, but we were given freedom on the language we chose to implement our assignments
    in. I decided that this project would be more easily modelled following an OOP paradigm. I believe the problem space
    is more easily translated this way. As such, I chose to implemented my assignment in C++ due to the ease in which it
    could be ported, the flexibility that the language provides and it's support of OOP. While this version of the code
    is not reflective of the current state of the project - which I would prefer to include. I am not allowed to
    showcase any project before its due date because of the Academic Integrity policy at the University of Guelph. A lot
    of refactoring has taken place as certain design decisions turned out to be less than ideal or caused regression
    bugs.

    For this part of the project I used inheritance to give a class the ability to be updated by the system. I used the
    singleton pattern to implement an update manager that controls when objects are updated. I created bindings so that
    my C++ code could call the C functions provided.

    The target system for this project is MacOS. Because I only have a Windows pc, I have also included instructions on
    how to get the project to run on Windows using WSL and launchX.

3. **Compilers - A1**  

    This assignment was intended to introduce JFlex and practice creating a scanner. I had to make a scanner that could
    recognize SGML(Standard Generalized Markup Language) files and filter out irrelavant data from these files. The
    filtering process was dependent on tags specified in the assignment outline. It required that any data between tags
    that aren't on the whitelist should be discarded. It was written in java and jflex.

4. **MachineLearning_DecisionTree**

    This assignment introduced machine learning concepts, specifically how a
    machine can learn in a discrete problem space. I implemented an algorithm
    to derive a decision tree given a problem space schema, and an example set.
