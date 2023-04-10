#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>

/* function prototypes for binary bits manipulation */
unsigned int binary_to_uint(const char *binary_str);
void print_binary(unsigned long int n);
int get_bit(unsigned long int n, unsigned int index);
int _putchar(char character);
int set_bit(unsigned long int *n, unsigned int index);
int clear_bit(unsigned long int *n, unsigned int index);
unsigned int flip_bits(unsigned long int n, unsigned long int m);


/* Function prototype for system endianness detection */
int get_endianness(void);

#endif /* MAIN.H */
