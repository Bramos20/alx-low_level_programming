#include "variadic_functions.h"

/**
 * sum_them_all - return the sum of all its parameters
 * @n: number of extra params
 * Return: total sum
 */
int sum_them_all(const unsigned int n, ...)
{
	unsigned int j;
	va_list list;
	int sum;

	va_start(list, n);
	for (j = 0, sum = 0; j < n; j++)
		sum += va_arg(list, int);

	va_end(list);

	return (sum);
}
