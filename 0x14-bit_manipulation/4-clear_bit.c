#include "main.h"

/**
 * clear_bit - Sets the value of a bit to 0 at a given index.
 * @n: Pointer to the decimal number to be changed.
 * @index: Index position to be changed.
 * Return: 1 if the operation was successful, -1 if there's an error.
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int bit_value;
	unsigned int temp_index;

	if (index > 64)
		return (-1);

	temp_index = index;
	for (bit_value = 1; temp_index > 0; bit_value *= 2, temp_index--)
		;

	if ((*n >> index) & 1)
		*n -= bit_value;

	return (1);
}
