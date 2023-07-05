#include <stdio.h>
#include <stdbool.h>

bool wildcmp_helper(char *s1, char *s2);

/**
 * wildcmp - Compares two strings and returns 1 if they can be considered identical.
 * @s1: The first string to compare.
 * @s2: The second string to compare.
 *
 * Return: 1 if the strings can be considered identical, 0 otherwise.
 */
int wildcmp(char *s1, char *s2)
{
	return wildcmp_helper(s1, s2);
}

/**
 * wildcmp_helper - Recursive helper function to compare two strings.
 * @s1: The first string to compare.
 * @s2: The second string to compare.
 *
 * Return: 1 if the strings can be considered identical, 0 otherwise.
 */
bool wildcmp_helper(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
	{
		return true; /* Base case: Both strings are empty, they are identical */
	}
	else if (*s1 == *s2 || *s2 == '*')
	{
		if (*s1 != '\0')
		{
			if (wildcmp_helper(s1 + 1, s2 + 1))
			{
				return true; /* Characters match or s2 has '*', continue comparing */
			}
		}

		if (*s2 == '*' && wildcmp_helper(s1, s2 + 1))
		{
			return true; /* Try to match '*' with empty string or continue matching */
		}
	}

	return false; /* Strings are not identical */
}
