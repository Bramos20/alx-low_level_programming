#include "main.h"

int sqrt_helper(int n, int start, int end);

/**
 * _sqrt_recursion - Returns the natural square root of a number.
 * @n: The number to calculate the square root of.
 *
 * Return: The natural square root of the number, or -1 if there is an error.
 *         If n does not have a natural square root, -1 is returned.
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
	{
		return (-1); /* Error: Invalid input */
	}
	else if (n == 0 || n == 1)
	{
		return (n);
	}
	else
	{
		return (sqrt_helper(n, 1, n / 2));
	}
}

/**
 * sqrt_helper - Recursive helper function to find the square root.
 * @n: The number to calculate the square root of.
 * @start: The start value for the search range.
 * @end: The end value for the search range.
 *
 * Return: The square root of the number if found, or the closest integer.
 */
int sqrt_helper(int n, int start, int end)
{
	int mid, result;

	if (start <= end)
	{
		mid = (start + end) / 2;
		result = mid * mid;

		if (result == n)
		{
			return (mid);
		}
		else if (result > n)
		{
			return (sqrt_helper(n, start, mid - 1));
		}
		else
		{
			return (sqrt_helper(n, mid + 1, end));
		}
	}

	return (end);
}
