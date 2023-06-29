#include <stdio.h>

/**
 * leet - Encodes a string into 1337 (Leet Speak).
 * @str: The string to encode.
 *
 * Return: Pointer to the encoded string.
 */
char *leet(char *str)
{
	char *letters = "aeotlAEOTL";
	char *leet_chars = "430710430710";
	int i, j;

	for (i = 0; str[i] != '\0'; i++)
	{
		for (j = 0; letters[j] != '\0'; j++)
		{
			if (str[i] == letters[j])
			{
				str[i] = leet_chars[j];
				break;
			}
		}
	}

	return str;
}
