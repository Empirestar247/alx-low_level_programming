#include "lists.h"

/**
 * add_nodeint_end - Add a new node at the end of a listint_t list.
 * @head: A pointer to the head of the listint_t list.
 * @n: The value to be assigned to the new node.
 *
 * Return: The address of the new element, or NULL if it failed.
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new_node, *temp;

	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->next = NULL;

	temp = *head;

	/* Place new_node first if head is NULL */
	if (temp == NULL)
		*head = new_node;
	else
	{
		/* If head is not NULL, and next is not NULL */
		while (temp->next != NULL)
			temp = temp->next; /* Go to the last node */

		/* Place our new node at the end */
		temp->next = new_node;
	}

	return (*head);
}

