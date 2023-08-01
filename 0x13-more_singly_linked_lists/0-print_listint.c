#include "lists.h"

/**
 * print_listint - Prints all the elements of a linked list of type listint_t.
 * @head: Pointer to the linked list to print.
 *
 * Return: Number of nodes in the linked list.
 */
size_t print_listint(const listint_t *head)
{
    size_t num_nodes = 0;

    while (head != NULL)
    {
        printf("%d\n", head->n);
        num_nodes++;
        head = head->next;
    }

    return (num_nodes);
}
