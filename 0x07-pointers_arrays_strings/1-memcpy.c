#include "main.h"

/**
 * _memcpy - a function that copies memory area
 * @dest: memory where data is stored
 * @src: memory where data is copied from
 * @n: number of bytes to copy
 *
 * Return: copied memory with n bytes changed
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}

	return (dest);
}
