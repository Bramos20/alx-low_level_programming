#include "main.h"
/**
 * print_last_digit - print the last digit of a number
 * @i: int type number
 * Return: return value of last digit
 */
int print_last_digit(int i)
{
	int ij;

	if (i < 0)
	{
		ij = -1 * (i % 10);
		_putchar(ij + '0');
		return (ij);
	}
	else
	{
		ij = i % 10;
		_putchar(ij + '0');
		return (ij);
	}
}
