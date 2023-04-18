#include <stdio.h>

/**
 * premain - prints a message before main function is executed
 *
 * This function is executed before the main function is called
 * and it prints a message to the standard output
 */
void __attribute__ ((constructor)) premain()

{
	printf("You're beat! and yet' you must allow,\n");
	printf("l bore my house upon my back!\n");
}
