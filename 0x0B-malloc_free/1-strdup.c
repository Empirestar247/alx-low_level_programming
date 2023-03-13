#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter.
 * @str: the string to duplicate
 *
 * Return: pointer to the duplicated string, or NULL if str is NULL or if memory
 * allocation fails.
 */
char *_strdup(char *str)
{
	char *dup;
	size_t len;

	if (str == NULL)
		return (NULL);

	len = strlen(str);
	dup = malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);

	memcpy(dup, str, len + 1);

	return (dup);
}

