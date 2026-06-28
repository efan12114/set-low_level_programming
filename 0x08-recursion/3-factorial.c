#include "main.h"

/**
 * factorial - returns the factorial of a given number
 * @n: the number to calculate the factorial of
 *
 * Return: factorial of n, or -1 if n is lower than 0
 */
int factorial(int n)
{
	/* ERROR CASE: If n is negative, the project says return -1 */
	if (n < 0)
	{
		return (-1);
	}

	/* BASE CASE: The factorial of 0 is 1. This stops the recursion. */
	if (n == 0)
	{
		return (1);
	}

	/* RECURSIVE STEP: n * (n - 1)! */
	return (n * factorial(n - 1));
}
