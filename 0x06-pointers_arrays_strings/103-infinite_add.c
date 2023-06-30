#include <stdio.h>
#include <string.h>

/**
 * infinite_add - Adds two numbers
 * @n1: The first number
 * @n2: The second number
 * @r: The buffer to store the result
 * @size_r: The buffer size
 *
 * Return: Pointer to the result (r) if successful, 0 otherwise
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int len1 = strlen(n1);
	int len2 = strlen(n2);
	int max_len = (len1 > len2) ? len1 : len2;
	int carry = 0;
	int sum;
	int i = 0;

	if (max_len + 1 > size_r)
		return (0);

	while (i < max_len)
	{
		int digit1 = (i < len1) ? (n1[len1 - 1 - i] - '0') : 0;
		int digit2 = (i < len2) ? (n2[len2 - 1 - i] - '0') : 0;

		sum = digit1 + digit2 + carry;
		carry = sum / 10;
		r[i] = (sum % 10) + '0';

		i++;
	}

	if (carry)
	{
		if (i >= size_r - 1)
			return (0);

		r[i] = carry + '0';
		i++;
	}

	r[i] = '\0';

	/* Reverse the result string */
	int start = 0;
	int end = i - 1;

	while (start < end)
	{
		char temp = r[start];
		r[start] = r[end];
		r[end] = temp;
		start++;
		end--;
	}

	return (r);
}
