#include "hash_tables.h"

/**
 * hash_djb2 - hash function implementing the djb2 algorithm
 * @str: string to hash
 * Return: hashed value
 */
unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int hsh;
	int i;

	hsh = 5381;
	while ((i = *str++))
		hsh = ((hsh << 5) + hsh) + i;  /* hsh * 33 + i */

	return (hsh);
}
