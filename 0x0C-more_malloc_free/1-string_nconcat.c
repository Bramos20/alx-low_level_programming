#include "main.h"
#include <string.h>

/**
 * string_nconcat - Concatenates two strings
 * @s1: Pointer to the first string
 * @s2: Pointer to the second string
 * @n: Number of bytes from s2 to concatenate
 *
 * Return: Pointer to the concatenated string or NULL on failure
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	unsigned int s1_len = strlen(s1);
	unsigned int s2_len = strlen(s2);

	if (n >= s2_len)
		n = s2_len;

	char *concatenated = malloc(s1_len + n + 1);
	if (concatenated == NULL)
		return NULL;

	strcpy(concatenated, s1);
	strncat(concatenated, s2, n);

	return concatenated;
}
