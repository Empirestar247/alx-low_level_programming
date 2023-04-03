#include <stdio.h>

/**
 * print_message - prints a message before main function
 * Return: nothing
 */
void __attribute__((constructor)) print_mesage()
{
	printf("you're beat! and yet, you must allow,\n");
	printf("l bore my house upon my back!\n");

}
