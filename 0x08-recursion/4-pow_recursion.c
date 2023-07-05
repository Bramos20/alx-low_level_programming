#include "main.h"

/**
 * _pow_recursion - Returns the value of x raised to the power of y.
 * @x: The base number.
 * @y: The exponent.
 *
 * Return: The value of x raised to the power of y.
 *         If y is less than 0, -1 is returned to indicate an error.
 *         If y is 0, the result is 1.
 */
int _pow_recursion(int x, int y)
{
	if (y < 0)
	{
		return (-1); /* Error: Invalid input */
	}
	else if (y == 0)
	{
		return (1); /* Base case: x raised to the power of 0 is 1 */
	}
	else
	{
		return (x * _pow_recursion(x, y - 1)); /* Recursive call to calculate power */
	}
}
