#include "lists.h"
#include <stdio.h>

/**
 * print_listint - Prints all elements of a `listint_t` linked list.
 * @head: Pointer to the head of the linked list.
 *
 * Return: Number of nodes in the linked list.
 */
size_t print_listint(const listint_t *head)
{
    const listint_t *current;
    size_t count;

    for (current = head, count = 0; current != NULL; count++, current = current->next)
        printf("%d\n", current->n);

    return (count);
}
