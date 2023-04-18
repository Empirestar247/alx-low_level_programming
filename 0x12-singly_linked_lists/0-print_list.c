#include "lists.h"

/**
 * print_list - prints all the elements of a list_t list
 * @head: pointer to the head of the list
 * Return: number of elements in the list
 */

size_t print_list(const list_t *head)
{
	size_t num_elem;

	num_elem = 0;
	while (head != NULL)
	{
		if (head->str == NULL)
			printf("[%d] %s\n", 0, "(nil)");
		else
			printf("[%d] %s\n", head->len, head->str);
		num_elem++;
		head = head->next;
	}
	return (num_elem);
}
