#include "main.h"
#include <stdio.h>

/**
 * clear_bit - Sets the value of a bit to 0 at a specified index.
 * @n: Pointer to the decimal number to change.
 * @index: The index position to change.
 * Return: 1 if successful, -1 if an error occurs.
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int mask;
	unsigned int shift_amount;

	if (index > 64)
		return (-1);

	shift_amount = index;
	for (mask = 1; shift_amount > 0; mask *= 2, shift_amount--)
		;

	if ((*n >> index) & 1)
		*n -= mask;

	return (1);
}
