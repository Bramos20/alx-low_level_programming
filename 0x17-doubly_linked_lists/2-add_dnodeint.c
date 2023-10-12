#include "lists.h"

/**
 * add_dnodeint - Add a new node to the beginning of a doubly linked list
 * @head: A double pointer to the head node of the list
 * @n: The value to store in the new node
 * Return: The address of the new node or NULL if the operation fails
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
    dlistint_t *tmp, *new;

    tmp = *head;
    new = malloc(sizeof(dlistint_t));

    if (new == NULL)
        return (NULL);

    new->n = n;
    new->prev = NULL;

    if (tmp == NULL)
        new->next = NULL;
    else
    {
        while (tmp->prev)
            tmp = tmp->prev;

        tmp->prev = new;
        new->next = tmp;
    }

    *head = new;

    return (*head);
}
