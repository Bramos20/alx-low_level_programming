#include "main.h"

/**
 * set_bit - Sets the value of a bit to 1 at a specified index.
 * @n: Pointer to a decimal number.
 * @index: The index position to be changed, starting from 0.
 * Return: 1 if successful, -1 if an error occurs.
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int power;

	if (index > 64)
		return (-1);

	for (power = 1; index > 0; index--, power *= 2)
		;
	*n += power;

	return (1);
}
