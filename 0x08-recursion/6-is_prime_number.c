#include "main.h"

/**
 * check_prime - checks recursively if a number is prime
 * @n: the number to check
 * @i: the divisor to test
 *
 * Return: 1 if prime, 0 if not
 */
int check_prime(int n, int i)
{
	/* If we reach n/2 without finding a divisor, it is prime */
	if (i * i > n)
		return (1);

	/* If n is divisible by i, it is not prime */
	if (n % i == 0)
		return (0);

	/* Check the next number */
	return (check_prime(n, i + 1));
}

/**
 * is_prime_number - identifies if a number is a prime number
 * @n: the number to check
 *
 * Return: 1 if prime, 0 if not
 */
int is_prime_number(int n)
{
	/* Prime numbers are greater than 1 */
	if (n <= 1)
		return (0);

	/* 2 and 3 are prime */
	if (n <= 3)
		return (1);

	/* Start checking from 2 */
	return (check_prime(n, 2));
}
