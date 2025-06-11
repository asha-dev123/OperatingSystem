                                                                         PROJECT-1-README


System Environment:

This project was developed and tested on a system running Ubuntu 22.04.3, a stable Linux 5.15.153.1 distribution ideal for development. The primary tool used for editing and managing the code was Visual Studio Code, a versatile code editor with extensive plugin support. The Xv6-public operating system was compiled and tested using the GCC [v compiler, which provided compatibility with the C language used for system-level programming in Xv6. To emulate the Xv6 environment, we used QEMU 1.15.0-1, a widely-used open-source hardware emulator, which allowed for testing Xv6 as though it were running on physical hardware. The combination of these tools created a robust development environment that allowed for seamless coding, compiling, and testing of Xv6 modifications, including new system calls and user commands.

Prerequisites:

1. Windows OS, WSL, xv6-public downloaded from "https://github.com/mit-pdos/xv6-public" and copied into ubuntu and a C compiler.

To compile and run the xv6:
> make clean
> make
> make qemu-nox


Part-1: Writing a Hello World Program in Xv6

1. Within the xv6 source, Created a hello.c file which when run outputs "Hello XV6!" to stdout.
2. Added "hello" program name to uprogrs list in Makefile.

Part-2: Modifying ls

The ls command has been enhanced based on the following requirements:

Key Changes:
1. Hidden Files and Directories:
Now, The files and directories that begin with a. (hidden files) are excluded from the output. The user can view hidden files and directories by providing the -a flag.

2. Directory Indicator:
A "/" is appended to the end of directory names to easily differentiate them from regular files.

Implementation Details:

1. Functionality:
-> The ls function reads the contents of the specified directory and outputs information for each file and directory.
-> The fmtname function is responsible for formatting the names, appending a "/" for directories.
-> The main function processes command-line arguments, including the -a flag, to control whether hidden files and directories are shown.

2. Multi-Directory Support:
The modified ls command supports listing the contents of multiple directories provided as arguments.

3. Output:
The command outputs file and directory details such as name, type, inode number, and size.

Flags:
-a: Displays hidden files and directories (those starting with a .).
Default Behavior: Hidden files and directories are not shown unless the -a flag is used.



Part 3: Writing Hello World Syscall

1. Added a system call named hello which can be invoked from xv6's shell by making slight additions to files user.h, usys.S, syscall.h, syscall.c, sysproc.c, proc.c, defs.h, Makefile within the xv6 source code.
2. Made a new c program named "hello_kernel"(Hence, we can use command "hello_kernel") for demonstrating usage of hello system call. This program invokes hello system call.
3. user.h has to be included in this program.
4. The code of hello system call that prints the line "Hello from the Kernel!" is written in proc.h
5. As we are supposed to demonstrate this functionality of invoking a system call in part-1's hello.c, wrote part-3's code in hello.c and commented it out. In order to check the functionality of part-3 using hello command, need to comment and uncomment specific code as suggested by comments within hello.c
6. Added "hello_kernel" program name to uprogrs list in Makefile.

Part 4: Implementing the sleep command

1. Within the xv6 source, Created a sleep.c file.
2. Added "sleep" program name to uprogrs list in Makefile.
3. Usage of sleep command -> "sleep <number of ticks>"
4. 100 ticks is equivalent to 1 second. To see if the program runs as intended, we can provide the ticks in multiples of 100.
5. The program makes a call to the already existing "sleep" system call and passes the number of ticks given through command line. If user didn't pass number of ticks, Error message is printed.


Additional Resources:

1. Discussing with the TA really helped us get a clearer picture of what was expected from the project.
2. Working closely with my groupmates made a huge difference. We split tasks efficiently, which allowed us to tackle different parts of the project simultaneously. The collaborative discussions helped ensure we all understood the concepts, especially when adding features like hiding hidden files in the ls command.
3. We referenced the official Unix documentation for ls and sleep commands to understand how they should behave. This was especially helpful when we wanted to replicate certain behaviors in Xv6, like adding a / to directory names or hiding hidden files.
4. Various online forums like Stack Overflow provided quick answers to issues we encountered, particularly with Makefile modifications and debugging problems with system calls.

Screenshots:

For each task in this project, the corresponding code and output screenshots have been provided in the attached Project 1 report document. These include:

The implementation of the hello.c file and its successful output of "Hello Xv6!".
Modifications made to the ls command, along with the updated output format.
The hello() syscall and its output, showing "Hello from the Kernel!".
The implementation of the sleep command, which correctly pauses for the specified number of ticks.
The screenshots capture the code files, the make process (including make clean, make, and make qemu), and the terminal output for each task. Please refer to the attached report for screenshots of each step in the project.



 




