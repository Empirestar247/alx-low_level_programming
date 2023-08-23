## 0x1C. C - Makefiles

## Resources
Read or watch:

Makefile
Installing the make utility
make-official documentation

## Learning Objectives
At the end of this project, you are expected to be able to explain to anyone, without the help of Google:

## General
What are make, Makefiles
When, why and how to use Makefiles
What are rules and how to set and use them
What are explicit and implicit rules
What are the most common / useful rules
What are variables and how to set and use them

## **Make** is a build automation tool that helps manage the compilation and linking of source code files into executable programs or libraries. A **Makefile** is a configuration file used by Make to define how source code files should be compiled, linked, and processed to generate the desired output.

Makefiles are used to streamline the build process of software projects. They specify the dependencies between source files, rules for building each target, and any additional commands needed for compilation and linking. By using Makefiles, developers can automate the build process, making it more efficient and error-free.

**Rules** in a Makefile define how to build a target file from its dependencies. A rule typically consists of a target, a list of prerequisites (dependencies), and a set of commands to execute. Rules can be used to describe how to compile source code, link object files, and generate the final executable.

**Explicit rules** are rules that explicitly define how to build a target using specific commands. **Implicit rules**, on the other hand, are predefined rules in Make that are used when no explicit rule is provided. Implicit rules apply based on file name patterns.

Common and useful **rules** in Makefiles include:
- `.c` to `.o` rule: Compiling C source files into object files.
- `.o` to executable rule: Linking object files into an executable.
- `.clean` rule: Removing generated files to clean up the directory.

**Variables** in Makefiles allow you to define and manage reusable values. They make it easier to customize build settings and avoid redundancy. Variables are usually defined at the beginning of the Makefile and can be used throughout the file.

Here's a simple example of a Makefile:

```make
CC = gcc
CFLAGS = -Wall -O2

myprogram: main.o util.o
    $(CC) $(CFLAGS) -o myprogram main.o util.o

main.o: main.c
    $(CC) $(CFLAGS) -c main.c

util.o: util.c
    $(CC) $(CFLAGS) -c util.c

clean:
    rm -f myprogram main.o util.o
```

In this example, `CC` and `CFLAGS` are variables for the compiler and compiler flags, respectively. Rules define how to build the target `myprogram` from its dependencies `main.o` and `util.o`.

Makefiles are powerful tools for automating the build process, managing dependencies, and improving code organization in software project.

## Requirements
General
Allowed editors: vi, vim, emacs
OS: Ubuntu 20.04 LTS
Version of gcc: 9.3.0
Version of make: GNU Make 4.2.1
All your files should end with a new line
A README.md file, at the root of the folder of the project, is mandatory

## Tasks
**0. make -f 0-Makefile**
**1. make -f 1-Makefile**
**2. make -f 2-Makefile**
**3. make -f 3-Makefile**
**4. A complete Makefile**
**5. Island Perimeter**
**6. make -f 100-Makefile**


