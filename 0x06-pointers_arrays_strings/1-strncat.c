#include "main.h"

/**
 * _strncat - concatenates two strings using at most n bytes from src
 * @dest: destination string
 * @src: source string
 * @n: limit of bytes to copy from src
 *
 * Return: pointer to the resulting string dest
 */
char *_strncat(char *dest, char *src, int n)
{
	int dest_len = 0;
	int i = 0;

	/* Find the end of dest string */
	while (dest[dest_len] != '\0')
	{
		dest_len++;
	}

	/* Append src to dest, but stop at n bytes or null terminator */
	while (i < n && src[i] != '\0')
	{
		dest[dest_len + i] = src[i];
		i++;
	}

	/* Always terminate with a null byte */
	dest[dest_len + i] = '\0';

	return (dest);
}
