#include <stdio.h>

/**
 * print - function that runs before main
 *
 * Return: nothing
 */
void __attribute__((constructor)) print()
{
	printf("you're beat! and yet, you must allow,\n");
	printf("l bore my house upon my back!\n");

}
