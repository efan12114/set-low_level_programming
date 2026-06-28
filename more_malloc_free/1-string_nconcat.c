#include "main.h"
#include <stdlib.h>

/**
 * string_nconcat - concatenates two strings
 * @s1: first string
 * @s2: second string
 * @n: number of bytes from s2 to concatenate
 *
 * Return: pointer to the new string, or NULL on failure
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *concat;
	unsigned int len1 = 0, len2 = 0, i, j;

	/* Treat NULL as empty strings */
	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	/* Calculate lengths */
	while (s1[len1])
		len1++;
	while (s2[len2])
		len2++;

	/* Use entire s2 if n is greater than or equal to its length */
	if (n >= len2)
		n = len2;

	/* Allocate memory: s1 length + n bytes of s2 + null terminator */
	concat = malloc(sizeof(char) * (len1 + n + 1));

	if (concat == NULL)
		return (NULL);

	/* Copy s1 into the new space */
	for (i = 0; i < len1; i++)
		concat[i] = s1[i];

	/* Copy n bytes of s2 into the new space */
	for (j = 0; j < n; j++, i++)
		concat[i] = s2[j];

	/* Add the final null terminator */
	concat[i] = '\0';

	return (concat);
}
