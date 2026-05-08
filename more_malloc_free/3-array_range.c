#include "main.h"
#include <stdlib.h>

/**
 * array_range - creates an array of integers
 * @min: the starting value (included)
 * @max: the ending value (included)
 *
 * Return: pointer to the newly created array, or NULL if it fails
 */
int *array_range(int min, int max)
{
	int *ptr;
	int i, size;

	/* 1. If min > max, return NULL per requirements */
	if (min > max)
		return (NULL);

	/* 2. Calculate the number of elements needed */
	/* We add 1 because both min and max are included */
	size = max - min + 1;

	/* 3. Allocate memory for 'size' number of integers */
	ptr = malloc(sizeof(int) * size);

	/* 4. Check if malloc failed */
	if (ptr == NULL)
		return (NULL);

	/* 5. Fill the array with the range of numbers */
	for (i = 0; i < size; i++)
	{
		ptr[i] = min++;
	}

	return (ptr);
}
