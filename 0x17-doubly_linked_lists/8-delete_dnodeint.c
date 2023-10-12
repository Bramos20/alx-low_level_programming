#include "lists.h"

/**
 * delete_dnodeint_at_index - Remove a node from a doubly linked list at a given index
 * @head: Double pointer to the head of the list
 * @index: Index position to delete a node from the list
 * Return: 1 if successful, -1 if the operation fails
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *tmp, *next, *prev;
	unsigned int c;

	if (*head == NULL)
		return (-1);

	for (tmp = *head, c = 0, prev = NULL; tmp && c < index; c++)
	{
		prev = tmp;
		tmp = tmp->next;
	}

	if (tmp == NULL)
		return (-1);

	next = tmp->next;

	if (prev == NULL)
	{
		free(tmp);

		if (next != NULL)
		{
			next->prev = NULL;
			*head = next;
		}
		else
			*head = NULL;
	}
	else if (next == NULL)
	{
		prev->next = NULL;
		free(tmp);
	}
	else
	{
		prev->next = next;
		next->prev = prev;
		free(tmp);
	}

	return (1);
}
