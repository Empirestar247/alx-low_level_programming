#include "dog.h"
#include <stdlib.h>

/**
 * _strdup - Duplicates a string in memory
 *
 * @str: String to duplicate
 *
 * Return: Pointer to the newly allocated space in memory, or NULL if it fails
 */
char *_strdup(char *str)
{
	char *dup_str;
	int i, len = 0;

	if (str == NULL)
		return (NULL);

	while (str[len] != '\0')
		len++;

	dup_str = malloc((sizeof(char) * len) + 1);

	if (dup_str == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
		dup_str[i] = str[i];

	dup_str[i] = '\0';

	return (dup_str);
}

/**
 * new_dog - Creates a new dog structure
 *
 * @name: Name of the dog
 * @age: Age of the dog
 * @owner: Owner of the dog
 *
 * Return: Pointer to the newly created dog structure, or NULL if it fails
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *new_dog;

	new_dog = malloc(sizeof(dog_t));

	if (new_dog == NULL)
		return (NULL);

	new_dog->name = _strdup(name);

	if (new_dog->name == NULL)
	{
		free(new_dog);
		return (NULL);
	}

	new_dog->age = age;

	new_dog->owner = _strdup(owner);

	if (new_dog->owner == NULL)
	{
		free(new_dog->name);
		free(new_dog);
		return (NULL);
	}

	return (new_dog);
}

