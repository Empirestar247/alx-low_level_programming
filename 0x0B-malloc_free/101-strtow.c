/**
 * strtow - Split a string into words
 * @str: The string to split
 *
 * Return: A pointer to an array of strings (words), or NULL if str is NULL or empty
 */
char **strtow(char *str)
{
	char **words;
	int i, j, num_words = 0, word_len = 0, start = 0, end = 0;

	if (str == NULL || *str == '\0')
		return (NULL);

	while (*(str + end))
	{
		if (*(str + start) == ' ')
			start++;
		else
		{
			end = start;
			while (*(str + end) != ' ' && *(str + end))
			{
				word_len++;
				end++;
			}
			num_words++;
			start = end;
			word_len = 0;
		}
	}

	words = malloc((num_words + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);

	for (i = 0, start = 0, end = 0; i < num_words; i++)
	{
		while (*(str + start) == ' ')
			start++;

		end = start;
		while (*(str + end) != ' ' && *(str + end))
		{
			word_len++;
			end++;
		}

		*(words + i) = malloc((word_len + 1) * sizeof(char));
		if (*(words + i) == NULL)
		{
			for (j = 0; j < i; j++)
				free(*(words + j));
			free(words);
			return (NULL);
		}

		for (j = 0; j < word_len; j++)
			*(*(words + i) + j) = *(str + start + j);

		*(*(words + i) + j) = '\0';
		start = end;
		word_len = 0;
	}

	*(words + i) = NULL;
	return (words);
}
