#include "lists.h"

/**
 * print_listint - prints all the element of a listint_t list
 * @h: pointer to head of  linked list
 *
 * Return: the number of nodes in the list
 */
size_t print_listint(const listint_t *h)
{
	size_t node =0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		node++;
		h = h->next;
	}
	return (node);
}
