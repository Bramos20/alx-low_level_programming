#include "main.h"

/**
 * main-Entrypoint
 * description: prints _putchar
 * Return- always 0
 */

int main(void)
{
	char task0[] = "_putchar";
	int i = 0;

	while (task0[i] != '\0')
	{
		_putchar(task0[i]);
		i++;
	}
	_putchar('\n');

	return (0);
}
