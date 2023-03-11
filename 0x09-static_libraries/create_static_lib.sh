#!/bin/bash
gcc -Wall -pedantic -Werror -Wextra -c *.c || exit 1
ar rc libell.a *.o || exit 1
