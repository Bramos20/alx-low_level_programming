#include <stdlib.h>
#include "lists.h"

/**
 * list_len - returns the number of elements in a list
 * @h: pointer to the list_t
 *
 * Return: number of elements in h
 */
size_t list_len(const list_t *h)
{
	size_t m = 0;

	while (h != NULL) {
		m++;
		h = h->next;
	}
	return m;
}
