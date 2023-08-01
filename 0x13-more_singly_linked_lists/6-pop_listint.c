#include "lists.h"

/**
 * pop_listint - Deletes the head node of a linked list of type listint_t.
 * @head: Pointer to the pointer of the first element in the linked list.
 *
 * Return: The data inside the element that was deleted, or 0 if the list is empty.
 */
int pop_listint(listint_t **head)
{
	listint_t *current;
	int data;

	if (!head || !*head)
		return (0);

	data = (*head)->n;
	current = (*head)->next;
	free(*head);
	*head = current;

	return (data);
}
