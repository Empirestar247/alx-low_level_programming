#include <stdlib.h>

/**
 * argstostr - Concatenates all the arguments of a program
 *
 * @ac: The number of arguments
 * @av: An array of strings containing the arguments
 *
 * Return: A pointer to the concatenated string, or NULL on failure
 */
char *argstostr(int ac, char **av)
{
	if (ac == 0 || av == NULL)
		return (NULL);

	int i, j, total_length = 0;
	char *arg, *str;

	for (i = 0; i < ac; i++)
	{
		arg = av[i];
		if (arg == NULL)
			continue;
		for (j = 0; arg[j] != '\0'; j++)
			total_length++;
		total_length++;
	}

	str = malloc(sizeof(char) * (total_length + 1));
	if (str == NULL)
		return (NULL);

	int pos;
	for (i = 0; i < ac; i++)
	{
		arg = av[i];
		if (arg == NULL)
			continue;
		pos = 0;
		while (*arg)
			str[pos++] = *arg++;
		str[pos++] = '\n';
	}
	str[pos] = '\0';

	return (str);
}

