#include "main.h"
#include <stdio.h>

/**
 * flip_bits - Calculates the number of bit flips required to convert one number to another.
 * @n: The first number.
 * @m: The second number to convert to.
 * Return: The count of bits that need to be flipped.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int difference;
	int bit_count;

	difference = n ^ m;
	bit_count = 0;

	while (difference)
	{
		bit_count++;
		difference &= (difference - 1);
	}

	return (bit_count);
}
