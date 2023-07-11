#include "main.h"
#include <stdlib.h>

/**
 * _strdup - Duplicate a string using malloc
 * @str: string to duplicate
 * Return: Pointer to a the new duped string
 */

char *_strdup(char *str)
{
	char *j;
	int i, c;

	if (str == NULL)
		return (NULL);

	for (i = 0; str[i] != '\0'; i++)
		;

	j = malloc(i * sizeof(*j) + 1);
	if (j == NULL)
		return (NULL);

	for (c = 0; c < i; c++)
		j[c] = str[c];
	j[c] = '\0';

	return (j);
}
