#include "main.h"
#include <stdio.h>

/**
 * binary_to_uint - Converts a binary number to an unsigned int.
 * @b: A string containing binary digits.
 * Return: The converted decimal number, or 0 if there are invalid chars.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int result, power;
	int length;

	if (b == NULL)
		return (0);

	for (length = 0; b[length]; length++)
	{
		if (b[length] != '0' && b[length] != '1')
			return (0);
	}

	for (power = 1, result = 0, length--; length >= 0; length--, power *= 2)
	{
		if (b[length] == '1')
			result += b;
	}

	return (result);
}
