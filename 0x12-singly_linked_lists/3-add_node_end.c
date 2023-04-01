#include "lists.h"

/**
 * add_node_end - adds a new node at the end of a list_t list.
 *
 * @head: pointer to a pointer to the head of the list_t list.
 * @str: string to be included in the new node.
 *
 * Return: Address of the new element, or NULL if it failed.
 */

list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new_node, *current;

	if (head == NULL || str == NULL)
		return (NULL);
	new_node = malloc(sizeof(list_t));
		return (NULL);

	new_node->str = strdup(str);
	if (new_node->str == NULL)
	{
		free(new_node);
		return (NULL);
	}

	new_node->len = _strlen(new_node->str);
	new_node->next = NULL;

	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}

	current = *head;
	while (current->next != NULL)
		current = current->next;

	current->next = new_node;

	return (new_node);
}

/**
 * _strlen - calculate the length of a string.
 * @str: string to be measured.
 *
 * Return: length of the string
 */

unsigned int _strlen(const char *str)
{
	unsigned int len;

	for (len = 0; str[len]; len++)
		;

	return (len);
}
