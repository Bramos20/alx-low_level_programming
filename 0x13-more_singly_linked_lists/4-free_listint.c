#include "lists.h"

/**
 * free_listint - Frees a linked list of type listint_t.
 * @head: Pointer to the listint_t list to be freed.
 */
void free_listint(listint_t *head)
{
	listint_t *current;

	while (head)
	{
		current = head->next;
		free(head);
		head = current;
	}
}
