#include "main.h"

/**
 * binary_to_uint - Converts a binary string to an unsigned integer.
 *
 * @binary_str: Pointer to the binary string to be converted.
 *
 * Return: The converted unsigned integer, or 0 if an error occurred.
 */
unsigned int binary_to_uint(const char *binary_str)
{
	unsigned int decimal_value = 0;

	/* Check for null pointer input */
	if (!binary_str)
		return (0);

	/* Traverse binary string, converting binary digits to decimal */
	while (binary_str && *binary_str)
	{
		/* Check for invalid binary digit */
		if (*binary_str < '0' || *binary_str > '1')
			return (0);

		/* Convert binary digit to decimal and add to total */
		decimal_value = decimal_value * 2 + (*binary_str - '0');
		binary_str++;
	}

	/* Return the resulting decimal value */
	return (decimal_value);
}
