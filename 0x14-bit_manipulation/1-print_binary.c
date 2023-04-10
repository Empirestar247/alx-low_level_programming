#include "main.h"

/**
 * print_binary - Prints the binary representation of a number.
 *
 * @n: The number to print in binary.
 */
void print_binary(unsigned long int n)
{
	unsigned long int mask = 1; /* Start with the least significant bit */
	int shift = 0;

	/* Find the most significant bit of the number */
	while ((n >> shift) > 1)
		shift++;

	/* Print the binary representation, one bit at a time */
	while (shift >= 0)
	{
		if ((n & (mask << shift)) == 0)
			_putchar('0');
		else
			_putchar('1');

		shift--;
	}
}
