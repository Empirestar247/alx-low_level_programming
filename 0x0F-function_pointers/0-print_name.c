#include <stdio.h>
#include "function_pointers.h"

void print_name(char *name, void (*f)(char *))
{
    size_t len = 0;
    while (name[len] != '\0') {
        len++;
    }
    char *buffer = (char *)malloc((len + 1) * sizeof(char));
    if (buffer == NULL) {
        exit(EXIT_FAILURE);
    }
    for (size_t i = 0; i <= len; i++) {
        buffer[i] = name[i];
    }
    f(buffer);
    free(buffer);
}

