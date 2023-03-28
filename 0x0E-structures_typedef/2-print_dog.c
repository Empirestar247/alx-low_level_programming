#include "dog.h"
#include <stdio.h>

/**
 * print_dog -print dog
 *
 * @d: pointer to struct dog
 *
 * Return: nothing
 */

void print_dog(struct dog *d)
{
	if (d != NULL)
	{
		printf("Name : %s\n", d->name == NULL ? "(nil)" : d->name);
		printf("Age: %f\n", d->age);
		printf("owner : %s\n", d->owner == NULL ? "(nil)" : d->owner);
	}
}

