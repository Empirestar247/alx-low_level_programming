#include "lists.h"

/**
 * get_dnodeint_at_index - Returns the node at the given index
 *
 * @head: Pointer to the head of the list
 * @index: Index of the node to retrieve
 *
 * Return: Address of the node at the given index, or NULL if not found
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
    unsigned int count = 0;

    if (head == NULL)
    {
        /* List is empty */
        return (NULL);
    }

    while (head != NULL)
    {
        if (index == count)
        {
            /* Node found at the given index */
            return (head);
        }
        count++;
        head = head->next;
    }

    /* Index is out of range */
    return (NULL);
}

