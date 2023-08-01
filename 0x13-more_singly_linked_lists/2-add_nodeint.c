#include "lists.h"

/**
 * add_nodeint_end - Adds a new node at the end of a `listint_t` list.
 * @head: Double pointer to the head node.
 * @n: Integer value to store in the new node.
 *
 * Return: Address of the new element or NULL if failed.
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
    listint_t *current;
    listint_t *new_node;

    for (current = *head; current && current->next != NULL; current = current->next)
        ;

    new_node = malloc(sizeof(listint_t));
    if (new_node == NULL)
        return (NULL);

    new_node->n = n;
    new_node->next = NULL;

    if (current)
        current->next = new_node;
    else
        *head = new_node;

    return (new_node);
}
