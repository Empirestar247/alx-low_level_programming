#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>

#define BUF_SIZE 1024

/**
 * error_exit - Prints an error message and exits with the given status code.
 *
 * @code: The status code to exit with.
 * @message: The error message to print.
 */
void error_exit(int code, char *message)
{
	dprintf(STDERR_FILENO, "%s", message);
	exit(code);
}

/**
 * main - Copies the contents of a file to another file.
 *
 * @argc: The number of arguments.
 * @argv: The array of arguments.
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	int file_from, file_to, bytes_read, bytes_written;
	char buffer[BUF_SIZE];
	struct stat st;

	if (argc != 3)
		error_exit(97, "Usage: cp file_from file_to\n");

	file_from = open(argv[1], O_RDONLY);
	if (file_from == -1)
		error_exit(98, "Error: Can't read from file %s\n", argv[1]);

	fstat(file_from, &st);

	file_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, st.st_mode & 0777);
	if (file_to == -1)
		error_exit(99, "Error: Can't write to %s\n", argv[2]);

	while ((bytes_read = read(file_from, buffer, BUF_SIZE)))
	{
		if (bytes_read == -1)
			error_exit(98, "Error: Can't read from file %s\n", argv[1]);

		bytes_written = write(file_to, buffer, bytes_read);
		if (bytes_written == -1)
			error_exit(99, "Error: Can't write to %s\n", argv[2]);

		if (bytes_written != bytes_read)
			error_exit(99, "Error: Incomplete write to %s\n", argv[2]);
	}

	if (close(file_from) == -1)
		error_exit(100, "Error: Can't close fd %d\n", file_from);

	if (close(file_to) == -1)
		error_exit(100, "Error: Can't close fd %d\n", file_to);

	return (0);
}
