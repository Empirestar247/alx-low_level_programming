#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

/**
 * main - prints the opcodes of its own main function
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	int i, bytes;
	char *opcodes;

	if (argc != 2)
	{
		write(STDERR_FILENO, "Error\n", 6);
			exit(1);
	}
		bytes = atoi(argv[1]);
		if (bytes < 0)
		{
		write(STDERR_FILENO, "Error\n", 6);
			exit(2);
		}
		opcodes = (char *) main;
	for (i = 0; i < bytes; i++)
	{
		printf("%02hhx ", opcodes[i]);
	}
		printf("\n");
		return (0);
}
