#include "lists.h"

/**
 * free_listint2 - Frees a linked list of type listint_t and sets head to NULL.
 * @head: Pointer to the pointer of the listint_t list to be freed.
 */
void free_listint2(listint_t **head)
{
	listint_t *current;

	if (head == NULL || *head == NULL)
		return;

	while (*head)
	{
		current = (*head)->next;
		free(*head);
		*head = current;
	}

	*head = NULL;
}
