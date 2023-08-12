#include "main.h"
#include <stdio.h>

/**
 * print_binary - Prints the binary representation of a decimal number.
 * @n: Decimal number to be printed as binary.
 */
void print_binary(unsigned long int n)
{
	unsigned long int temp;
	int shift_count;

	if (n == 0)
	{
		printf("0");
		return;
	}

	for (temp = n, shift_count = 0; (temp >>= 1) > 0; shift_count++)
		;

	for (; shift_count >= 0; shift_count--)
	{
		if ((n >> shift_count) & 1)
			printf("1");
		else
			printf("0");
	}
}
