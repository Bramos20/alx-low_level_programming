#include "main.h"

void puts_half(char *str)
{
	int length = 0;

	/* Calculate the length of the string */
	while (str[length] != '\0')
		length++;

	/* Calculate the number of characters to print */
	int n = (length - 1) / 2;

	/* Print the last n characters of the string */
	for (int i = length - n; i < length; i++)
	{
		putchar(str[i]);
	}

	putchar('\n');
}
