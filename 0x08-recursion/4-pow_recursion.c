#include "main.h"

/**
 * _pow_recursion - returns the value of x raised to the power of y
 * @x: the base value
 * @y: the exponent
 *
 * Return: result of the power, or -1 if y is negative
 */
int _pow_recursion(int x, int y)
{
	/* Error case: Negative exponent */
	if (y < 0)
	{
		return (-1);
	}

	/* Base case: x^0 is always 1 */
	if (y == 0)
	{
		return (1);
	}

	/* Recursive step: x * x^(y-1) */
	return (x * _pow_recursion(x, y - 1));
}
