#include "lists.h"

/**
 * listint_len - Counts the number of elements in a linked `listint_t` list.
 * @head: Pointer to the head of the linked list.
 *
 * Return: Number of elements in the linked list.
 */
size_t listint_len(const listint_t *head)
{
    const listint_t *current;
    size_t count;

    for (current = head, count = 0; current != NULL; count++, current = current->next)
        ;

    return (count);
}
