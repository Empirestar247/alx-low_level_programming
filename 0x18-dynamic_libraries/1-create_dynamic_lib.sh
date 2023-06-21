#!/bin/bash
gcc -Wall -pedantic -Werror -Wextra -c *.c
gcc -Wall -pedantic -Werror -Wextra -shared -o *.o
export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH
