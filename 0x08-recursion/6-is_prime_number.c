#include "main.h"

int fprime(int num, int div);
int is_prime_number(int n);

/**
 * fprime - Checks if a number is divisible.
 * @num: The number to be checked.
 * @k: The divisor.
 *
 * Return: If the number is divisible - 0.
 *         If the number is not divisible - 1.
 */

int fprime(int num, int k)
{
	if (num % k == 0)
		return (0);

	if (k == num / 2)
		return (1);

	return (fprime(num, ++k));
}

/**
 * is_prime_number - Checks if a number is prime
 * @n: The number to be checked
 *
 * Return: If the integer is not prime - 0.
 *         If the number is prime - 1.
 */

int is_prime_number(int n)
{
	int k = 2;

	if (n <= 1)
		return (0);

	if (n == 2 || n == 3)
		return (1);

	return (fprime(n, k));
}
