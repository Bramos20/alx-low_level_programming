#include "main.h"
#include <stdio.h>

/**
 * binary_to_uint - Convert a binary number to an unsigned int.
 * @b: A char string containing the binary number.
 * Return: The converted decimal number, or 0 if there's an unconvertible char.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0, base = 1;
	int length = 0;

	if (b == NULL)
		return (0);

	while (b[length])
	{
		if (b[length] != '0' && b[length] != '1')
			return (0);
		length++;
	}

	for (length--; length >= 0; length--, base *= 2)
	{
		if (b[length] == '1')
			result += base;
	}

	return (result);
}
