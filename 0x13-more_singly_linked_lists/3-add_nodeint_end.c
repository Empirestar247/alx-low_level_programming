#include "lists.h"

/**
 * add_nodeint_end - adds a new node at the end of a listint_t list
 * @head: a pointer to the pointer to the head node of the list
 * @n: the integer to be stored in the new node
 *
 * Return: if the function fails - NULL
 * otherwise - address of the new element
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new_node = malloc(sizeof(listint_t));

	if (!new_node)
		return (NULL);

	new_node->n = n;
	new_node->next = NULL;

	if (*head)
	{
		listint_t *tmp = *head;

		while (tmp->next)
			tmp = tmp->next;

				tmp->next = new_node;
	}
	else
		*head = new_node;

	return (new_node);
}
