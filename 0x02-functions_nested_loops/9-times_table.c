#include "main.h"
/**
 * times_table - Print the 9 times table, starting with 0
 * Return: 0
 */
void times_table(void)
{
	int i = 0; /* factor */
	int j; /* count  */
	int k; /* computed value */

	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			k = i * j;

			if (k > 9)
			{
				_putchar(k / 10 + '0');
				_putchar(k % 10 + '0');
			}
			else if (j != 0)
			{
				_putchar(' ');
				_putchar(k + '0');
			}
			else
			{
				_putchar(k + '0');
			}

			if (j != 9)
			{
				_putchar(',');
				_putchar(' ');
			}
		j++;
		}
		_putchar('\n');
		i++;
	}
}
