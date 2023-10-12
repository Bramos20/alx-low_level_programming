#include "lists.h"

/**
 * add_dnodeint_end - Add a new node to the end of a doubly linked list
 * @head: A double pointer to the head node
 * @n: The value to store in the new node
 * Return: The address of the new element or NULL if the operation fails
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *tmp, *new;

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = NULL;

	tmp = *head;

	while (tmp && tmp->next)
		tmp = tmp->next;

	if (tmp)
	{
		new->prev = tmp;
		tmp->next = new;
	}
	else
	{
		*head = new;
		new->prev = NULL;
	}

	return (new);
}
