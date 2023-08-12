#include "main.h"
#include <stdio.h>

/**
 * get_bit - Retrieves the value of a bit at a given index.
 * @n: Number to be evaluated.
 * @index: Index starting from 0 of the bit we want to retrieve.
 * Return: Value of bit at index, or -1 if there's an error.
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int bit_value;

	if (index > 64)
		return (-1);

	bit_value = n >> index;

	return (bit_value & 1);
}
