#include <main.h>
#include <stdlib.h>
#include <string.h>
/**
 * argstostr - concatenates all the arguments of a program
 * @ac: the number of arguments
 * @av: an array of strings representing the arguments
 *
 * Return: a pointer to a new string that contains the concatenated arguments
 *         with each argument followed by a newline character, or NULL if ac is
 *         0 or av is NULL or if memory allocation fails.
 */
char *argstostr(int ac, char **av)
{
    int i, j, len, total_len;
    char *str;

    if (ac == 0 || av == NULL)
        return (NULL);

    /* Compute the total length of the concatenated string */
    for (i = 0, total_len = 0; i < ac; i++)
    {
        for (len = 0; av[i][len]; len++)
            total_len++;

        total_len++; /* Add 1 for the \n character */
    }

    /* Allocate memory for the concatenated string */
    str = malloc(sizeof(char) * total_len);
    if (str == NULL)
        return (NULL);

    /* Concatenate the arguments with \n characters */
    for (i = 0, j = 0; i < ac; i++)
    {
        for (len = 0; av[i][len]; len++)
            str[j++] = av[i][len];

        str[j++] = '\n';
    }

    str[j] = '\0'; /* Add the null terminator */

    return (str);
}

