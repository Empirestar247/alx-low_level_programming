#include "lists.h"
#include <stddef.h>

/**
 * listint_len -  returns the number of elements in a linked listint list
 * @h: pointer to the head of the list
 *
 * Return: number of the nodes
 */
size_t listint_len(const listint_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		count++;
		h = h->next;
	}

	return (count);
}
