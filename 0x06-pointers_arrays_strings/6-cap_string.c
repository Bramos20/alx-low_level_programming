#include <stdio.h>
#include <ctype.h>

/**
 * cap_string - Capitalizes all words of a string.
 * @str: The string to modify.
 *
 * Return: Pointer to the modified string.
 */
char *cap_string(char *str)
{
	int i = 0;
	int capitalize = 1;

	/* Iterate over each character in the string */
	while (str[i] != '\0')
	{
		/* Check if the character is a separator or whitespace */
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == ',' ||
		    str[i] == ';' || str[i] == '.' || str[i] == '!' || str[i] == '?' ||
		    str[i] == '"' || str[i] == '(' || str[i] == ')' || str[i] == '{' ||
		    str[i] == '}')
		{
			capitalize = 1; /* Set the flag to capitalize the next character */
		}
		/* Check if the character is an alphabetic character */
		else if (isalpha(str[i]))
		{
			if (capitalize)
			{
				str[i] = toupper(str[i]); /* Capitalize the current character */
				capitalize = 0; /* Reset the flag */
			}
			else
			{
				str[i] = tolower(str[i]); /* Convert the character to lowercase */
			}
		}
		i++;
	}

	return str;
}
