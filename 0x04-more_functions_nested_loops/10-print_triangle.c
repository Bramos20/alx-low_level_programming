#include "main.h"

/**
 * print_triangle - print a triangle aligned right, using '#'
 * @size: Size of triangle
 */
void print_triangle(int size)
{
	int k, i, j;

	k = 0;
	i = size - 1;
	while (k < size)
	{
		i = size - 1 - k;
		j = k + 1;
		while (i > 0)
		{
			_putchar(' ');
			i--;
		}
		while (j > 0)
		{
			_putchar('#');
			j--;
		}
		_putchar('\n');
		k++;
	}

	if (size <= 0)
		_putchar('\n');
}
