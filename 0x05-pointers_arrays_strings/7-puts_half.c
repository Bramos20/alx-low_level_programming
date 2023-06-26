#include <stdio.h>

void puts_half(char *str)
{
	int l = 0;
	int n, i;

	/* Calculate the length of the string */
	while (str[l] != '\0')
		l++;

	/* Calculate the number of characters to print */
	n = (l - 1) / 2;

	/* Print the last n characters of the string */
	for (i = l - n; i < l; i++)
	{
		putchar(str[i]);
	}

	putchar('\n');
}
