#include <stdlib.h>
#include "main.h"
char *create_array(unsigned int size, char c) {
    if (size == 0) {
        return NULL;
    }

    char *arr = (char *) malloc(sizeof(char) * size);
    if (arr == NULL) {
        return NULL;
    }

    for (unsigned int i = 0; i < size; i++) {
        *(arr + i) = c;
    }

    return arr;
}

int main() {
    char *arr = create_array(5, 'a');
    if (arr == NULL) {
        return 1;
    }

    for (unsigned int i = 0; i < 5; i++) {
        *(arr + i) = 'b';
    }

    free(arr);
    return 0;
}

