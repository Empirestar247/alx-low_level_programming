#include "main.h"

/**
 * create_file - creates a file with given text content
 * @filename: the name of the file to create
 * @text_content: the text content to write to the file
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int fd, num_written, length = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		while (text_content[length] != '\0')
			length++;
	}

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fd == -1)
		return (-1);

	if (length > 0)
	{
		num_written = write(fd, text_content, length);
		if (num_written == -1)
		{
			close(fd);
			return (-1);
		}
	}

	close(fd);

	return (1);
}
