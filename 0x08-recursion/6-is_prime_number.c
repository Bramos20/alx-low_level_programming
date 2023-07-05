#include "main.h"

int is_prime_helper(int n, int divisor);

/**
 * is_prime_number - Checks if a number is prime.
 * @n: The number to check.
 *
 * Return: 1 if the number is prime, 0 otherwise.
 */
int is_prime_number(int n)
{
	if (n <= 1)
	{
		return (0); /* Numbers less than or equal to 1 are not prime */
	}
	else
	{
		return (is_prime_helper(n, 2)); /* Recursive helper function */
	}
}

/**
 * is_prime_helper - Recursive helper function to check if a number is prime.
 * @n: The number to check.
 * @divisor: The divisor to check.
 *
 * Return: 1 if the number is prime, 0 otherwise.
 */
int is_prime_helper(int n, int divisor)
{
	if (divisor == n)
	{
		return (1); /* Base case: Reached the end, number is prime */
	}
	else if (n % divisor == 0)
	{
		return (0); /* Number is divisible by divisor, not prime */
	}
	else
	{
		return (is_prime_helper(n, divisor + 1)); /* Check next divisor */
	}
}
