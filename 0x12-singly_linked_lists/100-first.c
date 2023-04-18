#include <stdio.h>

/**
 * premain - function that runs before main
 *
 */
void __attribute__ ((constructor))premain()
{
	printf("You're beat! and yet' you must allow,\n");
	printf("l bore my house upon my back!\n");
}
