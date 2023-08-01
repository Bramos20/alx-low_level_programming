#include "lists.h"

/**
 * pop_listint - Deletes the head node of a listint_t linked list.
 * @head: Pointer to the pointer of the first element in the linked list.
 *
 * Return: The data inside the element that was deleted, or 0 if the list is empty.
 */
int pop_listint(listint_t **head)
{
	int data = 0;

	if (head && *head)
	{
		listint_t *temp = *head;
		data = temp->n;
		*head = temp->next;
		free(temp);
	}

	return (data);
}
