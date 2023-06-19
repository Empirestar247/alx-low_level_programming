C - Dynamic libraries

Dynamic libraries, also known as shared libraries, are collections of precompiled functions and code that can be used by multiple programs simultaneously. They are a fundamental component of the C programming language and are used to modularize code and enable code reuse.

Dynamic libraries offer several advantages over static libraries. Here are some key features and benefits of dynamic libraries:

Code reusability: Dynamic libraries allow multiple programs to share a single copy of the library code. This promotes code reuse, reduces duplication, and makes applications more efficient in terms of disk space usage.

Run-time linking: Dynamic libraries are linked at run-time, which means that the necessary library functions are loaded into memory only when they are needed. This allows for more flexibility and efficient memory usage since the libraries are not loaded until explicitly required.

Easy updates and maintenance: Since dynamic libraries are separate files from the main executable, they can be updated independently without recompiling the entire program. This makes it easier to fix bugs, add new features, or improve the performance of the library code without affecting the existing applications.

Shared resources: Dynamic libraries can provide shared resources and services to multiple programs. For example, a graphics library can provide functions for rendering graphics that can be used by various applications, saving developers from reinventing the wheel.

Reduced executable size: Dynamic libraries can reduce the size of the executable file because they are loaded into memory at runtime. This can be particularly beneficial for large applications that use multiple libraries, as it helps to keep the size of the main executable manageable.



When a program is linked against a dynamic library, it only includes references to the functions provided by the library, rather than the actual code. The actual code resides in a separate shared library file. At runtime, when the program is executed, the operating system loads the required dynamic libraries into memory and resolves the function calls made by the program to the corresponding functions in the library.

To create a dynamic library, you typically follow these steps:

Write the library code: Create the source code files containing the functions and code that you want to include in the library.

Compile the library: Compile the source code into a shared library file. The exact compilation process depends on your platform. For example, on Unix-like systems, you can use the -shared option with the compiler, such as gcc -shared -o libexample.so example.c, to generate a shared library file named libexample.so.

Link against the library: When compiling your main program, specify the library dependencies using the -l option followed by the library name (without the lib prefix and file extension). For example, if you created libexample.so, you would use -lexample during compilation.

To use a dynamic library in your program, you need to make sure it can be found by the operating system at runtime. This is where the $LD_LIBRARY_PATH environment variable comes into play. It is an environment variable that specifies directories where the operating system should search for dynamic libraries.

You can set the $LD_LIBRARY_PATH variable by assigning it a list of directories separated by colons (:) in Unix-like systems or semicolons (;) in Windows. For example, export LD_LIBRARY_PATH=/path/to/libraries on Unix-like systems.

When your program is executed, the operating system checks the directories specified in $LD_LIBRARY_PATH to find the required dynamic libraries. If the library is found, it is loaded into memory, and the program can successfully link to and use the functions provided by the library.

 The differences between static and shared libraries:

 Static Libraries:

Compiled code is directly incorporated into the executable file.
The executable becomes self-contained and does not require external dependencies.
Results in larger executable files.
Each program using the library has its own copy of the library code in memory.
No runtime loading or linking is necessary.
Shared Libraries:

The library code is stored separately in shared library files.
Multiple programs can share the same library file.
Results in smaller executable files.
The library is loaded into memory at runtime and shared among programs.
Allows for easy updates and maintenance of the library without recompiling programs.

The basic usage of the nm, ldd, and ldconfig commands:

nm: The nm command is used to list symbols from object files and libraries. It displays the names of functions, variables, and other symbols defined in the object files or libraries. For example, nm libexample.so will display the symbols defined in the libexample.so shared library.

ldd: The ldd command is used to show the shared library dependencies of an executable or shared library. It lists the libraries that an executable or shared library depends on, including their locations. For example, ldd myprogram will display the shared libraries required by myprogram.


The ldconfig command is used to configure the runtime linker/loader cache. On Unix-like systems, it maintains a cache of shared libraries to improve the performance of locating and loading dynamic libraries.

Here are some key points about ldconfig:

ldconfig updates the system's cache by scanning specified directories (usually predefined system library directories) for shared libraries and creating or updating the cache accordingly.

It is typically run with administrative privileges (e.g., using sudo ldconfig) to ensure proper access to system directories.

Running ldconfig is often necessary after installing or updating shared libraries, as it updates the cache and allows the linker/loader to find the libraries during runtime.

The cache created by ldconfig is used by the runtime linker/loader to locate shared libraries specified in the executable's dependencies.

By default, the cache file is located at /etc/ld.so.cache or /etc/ld.so.cache.d/ (on some systems), but the exact location can vary.

The cache can be manually updated by running sudo ldconfig after adding or removing shared libraries from the system.


These commands (nm, ldd, and ldconfig) provide useful functionality for working with dynamic libraries. nm helps inspect the symbols in libraries, ldd shows library dependencies, and ldconfig maintains the library cache for efficient loading of dynamic libraries.
