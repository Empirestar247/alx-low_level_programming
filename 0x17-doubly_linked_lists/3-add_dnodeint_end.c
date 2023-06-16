#include "lists.h"

/**
 * add_dnodeint_end - Adds a new node at the end of a doubly linked list
 *
 * @head: Pointer to the head of the list
 * @n: Value to be stored in the new node
 *
 * Return: Address of the new element, or NULL if it failed
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
    dlistint_t *new_node = NULL, *end = *head;

    new_node = malloc(sizeof(dlistint_t));

    if (new_node == NULL)
    {
        /* Allocation failed */
        return (NULL);
    }

    new_node->n = n;
    new_node->prev = NULL;
    new_node->next = NULL;

    if (*head == NULL)
    {
        /* If the list is empty, make the new node the head */
        *head = new_node;
    }
    else
    {
        /* Traverse to the end of the list */
        while (end->next != NULL)
        {
            end = end->next;
        }

        /* Update the links to add the new node at the end */
        new_node->prev = end;
        end->next = new_node;
    }

    return (new_node);
}

