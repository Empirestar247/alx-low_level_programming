#include "lists.h"
#include <stdlib.h>

/**
 * add_nodeint_end - adds a new node at the end of a listint_t list
 * @head: a pointer to the pointer to the head node of the list
 * @n: the integer to be stored in the new node
 *
 * Return: the address of the element or NULL if failed
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new_node, *last_node;

	if (head == NULL)
		return (NULL);
	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->next = NULL;

	if (*head == NULL)
	{
		/* The list is empty, the new node becomes the head */
		*head = new_node;
	}
	else
	{
		/* Traverse the list to find the last node */
		last_node = *head;
		while (last_node->next != NULL)
		{
			last_node->next = new_node;
		}
		/* Append the new node to the end of the list */
		last_node->next = new_node;
	}

	return (new_node);
}
