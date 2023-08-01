#include <stdlib.h>
#include "lists.h"

/**
 * list_len - Returns the number of elements in a linked list_t
 * @h: head of linked list
 * Return: number of elements in list
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
