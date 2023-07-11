#include "main.h"
#include <stdlib.h>

/**
 * create_array - create an array of chars, and initialize with specific char
 * @size: size of array
 * @c: specific char
 * Return: char pointer to malloc created memory address or NULL if error
 */

char *create_array(unsigned int size, char c)
{
	char *j;
	unsigned int i;

	if (size == 0)
		return (NULL);

	j = malloc(size * sizeof(*j));
	if (j == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		j[i] = c;

	return (j);
}
