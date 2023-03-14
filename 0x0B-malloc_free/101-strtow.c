#include <stdlib.h>
#include <stddef.h>

/**
 * strtow - splits a string into words
 * @str: string to be split
 *
 * Return: pointer to an array of strings
 */
char **strtow(char *str)
{
        int i, j, k, num_words = 0;
        char **words, *word_start;

        if (str == NULL || *str == '\0')
                return (NULL);

        /* Count the number of words in the string */
        for (i = 0; str[i] != '\0'; i++)
                if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
                        num_words++;

        /* Allocate memory for the words array */
        words = malloc((num_words + 1) * sizeof(char *));
        if (words == NULL)
                return (NULL);

        /* Extract each word and store it in the words array */
        for (i = 0, j = 0; j < num_words; i++)
                if (str[i] != ' ')
                {
                        word_start = str + i;
                        for (k = 0; str[i] != ' ' && str[i] != '\0'; i++, k++)
                                ;
                        words[j] = malloc((k + 1) * sizeof(char));
                        if (words[j] == NULL)
                        {
                                /* Free all previously allocated memory */
                                for (i = 0; i < j; i++)
                                        free(words[i]);
                                free(words);
                                return (NULL);
                        }
                        for (k = 0; word_start[k] != ' ' && word_start[k] != '\0'; k++)
                                words[j][k] = word_start[k];
                        words[j][k] = '\0';
                        j++;
                }
        words[j] = NULL;

        return (words);
}

