#include "main.h"

/**
 * _strlen - return the length of the string
 * @s: char type pointer
 * Return: length of string
 */

int _strlen(char *s)
{
	int l;

	for (l = 0; s[l] != '\0'; l++)
		;

	return (l);
}
