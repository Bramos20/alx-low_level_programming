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

	while (str[i] != '\0')
	{
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == ',' ||
		    str[i] == ';' || str[i] == '.' || str[i] == '!' || str[i] == '?' ||
		    str[i] == '"' || str[i] == '(' || str[i] == ')' || str[i] == '{' ||
		    str[i] == '}')
		{
			capitalize = 1;
		}
		else if (isalpha(str[i]))
		{
			if (capitalize)
			{
				str[i] = toupper(str[i]);
				capitalize = 0;
			}
			else
			{
				str[i] = tolower(str[i]);
			}
		}
		i++;
	}

	return str;
}
