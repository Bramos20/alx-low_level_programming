#include "main.h"

/**
 * set_bit - Sets the value of a bit to 1 at a given index.
 * @n: Pointer to the decimal number.
 * @index: Index position to change, starting from 0.
 * Return: 1 if the operation was successful, -1 if there's an error.
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int position_value;

	if (index > 64)
		return (-1);

	for (position_value = 1; index > 0; index--, position_value *= 2)
		;
	*n += position_value;

	return (1);
}
