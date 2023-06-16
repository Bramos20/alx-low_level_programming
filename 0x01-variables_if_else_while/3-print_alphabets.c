#include <stdio.h>
/**
 * main - main block
 * Description: Use `putchar` to print lowercase and then uppercase alphabet.
 * Return: 0
 */
int main(void)
{
	char n = 'a';

	while (n <= 'z')
	{
		putchar(n);
		n++;
	}

	n = 'A';

	while (n <= 'Z')
	{
		putchar(n);
		n++;
	}

	putchar('\n');

	return (0);
}
