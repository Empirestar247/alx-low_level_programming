#include "lists.h"

/**
 * print_listint_safe - Prints a linked list
 * @head: A pointer to the head of the list
 *
 * Return: The number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
    const listint_t *current = head;
    size_t count = 0;

    while (current)
    {
        printf("[%p] %d\n", (void *) current, current->n);
        count++;
        /* Move to the next node */
        current = current->next;
        /* Check if we have reached the end of the list or if we have already printed the address */
        if (current == NULL || current < head)
        {
            break;
        }
    }

    /* Check if the loop ended due to the end of the list or due to a loop */
    if (current)
    {
        printf("-> [%p] %d\n", (void *) current, current->n);
    }

    return count;
}

