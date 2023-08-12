#include "main.h"

/**
 * flip_bits - Counts the number of bits to flip in order to convert one number to another.
 * @n: First number.
 * @m: Second number to convert to.
 * Return: Number of bits that need to be flipped.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int difference;
	int bit_counter;

	difference = n ^ m;
	bit_counter = 0;

	while (difference)
	{
		bit_counter++;
		difference &= (difference - 1);
	}

	return (bit_counter);
}
