#include <stdio.h>

/**
 * _memcpy - Copies n bytes from memory area src to memory area dest
 * @dest: Pointer to the destination memory area
 * @src: Pointer to the source memory area
 * @n: Number of bytes to copy
 *
 * Return: Pointer to the destination memory area (dest)
 */
char *_memcpy(char *dest, const char *src, unsigned int n)
{
	char *destPtr = dest;
	const char *srcPtr = src;

	while (n > 0)
	{
		*destPtr = *srcPtr;
		destPtr++;
		srcPtr++;
		n--;
	}

	return dest;
}
