#include "lists.h"

/**
 * print_dlistint - Prints the values of each node in a doubly linked list
 * @h: A pointer to the head of the doubly linked list
 * Return: The number of nodes in the linked list
 */
size_t print_dlistint(const dlistint_t *h)
{
	const dlistint_t *temp;
	size_t count;

	temp = h;
	while (temp && temp->prev)
		temp = temp->prev;

	for (count = 0; temp; count++, temp = temp->next)
		printf("%d\n", temp->n);

	return (count);
}
