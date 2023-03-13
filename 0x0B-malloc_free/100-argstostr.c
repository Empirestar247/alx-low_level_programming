#include <stdlib.h>
#include <stdio.h>

/**
 * argstostr - concatenates all the arguments of the program
 * @ac: argument count
 * @av: argument vector
 *
 * Return: pointer to the new string, or NULL if it fails
 * Each argument should be followed by a \n in the new string
 */
char *argstostr(int ac, char **av)
{
        char *str;
        int i, j, len = 0, index = 0;

        if (ac == 0 || av == NULL)
                return (NULL);

        for (i = 0; i < ac; i++)
        {
                for (j = 0; av[i][j]; j++)
                        len++;
                len++;
        }

        str = malloc(sizeof(char) * (len + 1));
        if (str == NULL)
                return (NULL);

        for (i = 0; i < ac; i++)
        {
                for (j = 0; av[i][j]; j++)
                {
                        str[index] = av[i][j];
                        index++;
                }
                str[index] = '\n';
                index++;
        }

        str[index] = '\0';
        return (str);
}

int main(int argc, char **argv)
{
        char *concatenated_args;

        if (argc < 2)
        {
                printf("Usage: %s arg1 arg2 ... argN\n", argv[0]);
                return (1);
        }

        concatenated_args = argstostr(argc - 1, argv + 1);
        if (concatenated_args == NULL)
        {
                printf("Error: failed to concatenate arguments\n");
                return (1);
        }

        printf("%s", concatenated_args);
        free(concatenated_args);
        return (0);
}

