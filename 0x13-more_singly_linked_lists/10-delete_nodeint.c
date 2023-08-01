#include "lists.h"

/**
 * delete_nodeint_at_index - Deletes the node at a given index in a listint_t linked list.
 * @head: Pointer to the pointer of the head of the linked list.
 * @index: Index of the node to be deleted, starting at 0.
 *
 * Return: 1 if the deletion succeeded, -1 if it failed.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int count = 0;
	listint_t *prev_node, *current_node;

	if (head == NULL || *head == NULL)
		return (-1);

	current_node = *head;
	if (index == 0)
	{
		*head = (*head)->next;
		free(current_node);
		return (1);
	}

	while (current_node != NULL)
	{
		if (count == index)
		{
			prev_node->next = current_node->next;
			free(current_node);
			return (1);
		}

		prev_node = current_node;
		current_node = current_node->next;
		count++;
	}

	return (-1);
}
