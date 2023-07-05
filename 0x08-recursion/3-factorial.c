#include "main.h"

/**
 * factorial - Returns the factorial of a given number.
 * @n: The number to calculate the factorial of.
 *
 * Return: The factorial of the number, or -1 if there is an error.
 *         If n is less than 0, -1 is returned to indicate an error.
 *         If n is 0, the factorial is 1.
 */
int factorial(int n)
{
	if (n < 0)
	{
		return (-1); /* Error: Invalid input */
	}
	else if (n == 0)
	{
		return (1); /* Base case: factorial of 0 is 1 */
	}
	else
	{
		return (n * factorial(n - 1)); /* Recursive call to calculate factorial */
	}
}
