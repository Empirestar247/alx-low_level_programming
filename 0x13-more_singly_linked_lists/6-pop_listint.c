#include "lists.h"
#include <stdlib.h>

/**
 * pop_listint - deletes the head node of a listint_t linked list
 * and returns the head node's data (n)
 * @head: pointer to the listint_t list
 *
 * Return: the data (n) of the head node that was deleted
 * or if the linked list is empty
 */
int pop_listint(listint_t **head)
{
	listint_t *temp;

	int n;
	if (*head == NULL)
		return (0);

	n = (*head)->n;
	temp = *head;
	*head = (*head)->next;
	free(temp);

	return (n);
}
