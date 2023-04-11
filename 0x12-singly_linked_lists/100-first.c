#include <stdio.h>

/**
 * beforeMain - Prints a message to the console before main is executed
 *
 * Description: This function prints the text
 * "You're beat! and yet, you must allow,"
 * and "I bore my house upon my back!"
 * to the console using the printf function.
 * Each line of text is terminated with a newline character (\n).
 */

/* Function to print the desired text to the console */
void beforeMain(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}

/**
 * main - Entry point of the program
 *
 * Description: This function serves as the entry
 * point of the program. It calls
 * the beforeMain function to print a message to the console,
 * and then prints the
 * string "Hello, world!" to the console
 * using the printf function. The function
 * returns 0 to indicate successful completion of the program.
 *
 * Return: 0 on successful completion of the program
 */

/* Main function that calls beforeMain and prints a message to the console */
int main(void)
{
	/* Call the beforeMain function to print the desired text to the console */
	beforeMain();

	/* Print a message to the console */
	printf("Hello, world!\n");

	/* Exit the program with a status of 0 to indicate successful completion */
	return (0);
}
