#include <stdio.h>
/**
 * main - main block
 * Description: Print all possible combinations fo single-digit numbers.
 * Numbers must be separated by commas and a space.
 * You can only use `putchar` to print to console
 * You can only use `putchar` up to four times.
 * You are not allowed to use any variable of type `char`.
 * Return: 0
 */
int main(void)
{
	int n = 0;

	while (n < 10)
	{
		putchar(n + '0');
		if (n < 9)
		{
			putchar(44);
			putchar(32);
		}
		n++;
	}
	putchar('\n');

	return (0);
}
