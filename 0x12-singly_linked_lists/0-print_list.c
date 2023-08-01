#include <stdio.h>
#include "lists.h"

/**
 * print_list - prints all the elements of list_t list
 * @h: pointer to the list_t  to print
 *
 * Return: the number of nodes printed m
 */
size_t print_list(const list_t *h)
{
	size_t m;

	m = 0;

	while (h)
	{
		if (!h->str)
			printf("[0] (nil)\n");
		else
			printf("[%d] %s\n", h->len, h->str);
		h = h->next;
		m++;
	}

	return (m);
}
