#include "main.h"

/**
 * _puts_recursion - Prints a string recursively
 *
 * @s: Pointer to the string to print
 *
 * Return: void
 */
void _puts_recursion(char *s)
{
	if (*s)
	{
		_putchar(*s);
		_puts_recursion(s + 1);
	}
	else
	{
		_putchar('\n');
	}
}

