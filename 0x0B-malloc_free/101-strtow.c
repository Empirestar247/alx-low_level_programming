#include <string.h>
#include <stdlib.h>

/**
 * strtow - Splits a string into words
 * @str: Pointer to the string to split
 *
 * Return: Pointer to an array of strings (words)
 *         Each element of this array should contain a single word, null-terminated
 *         The last element of the returned array should be NULL
 *         Returns NULL if str == NULL or str == ""
 **/
char **strtow(char *str)
{
        char **words = NULL;
        int i, j, k, len, word_count = 0;

        if (str == NULL || *str == '\0')
                return (NULL);

        len = strlen(str);

        for (i = 0; i < len; i++)
        {
                if (str[i] != ' ' && (i == 0 || str[i - 1] == ' '))
                        word_count++;
        }

        words = malloc(sizeof(char *) * (word_count + 1));

        if (words == NULL)
                return (NULL);

        for (i = 0, j = 0; j < word_count; j++)
        {
                while (str[i] == ' ')
                        i++;

                k = i;

                while (str[i] != ' ' && str[i] != '\0')
                        i++;

                words[j] = malloc(sizeof(char) * (i - k + 1));

                if (words[j] == NULL)
                {
                        while (--j >= 0)
                                free(words[j]);

                        free(words);
                        return (NULL);
                }

                strncpy(words[j], &str[k], i - k);
                words[j][i - k] = '\0';
        }

        words[word_count] = NULL;

        return (words);
}

