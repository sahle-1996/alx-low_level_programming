#include "main.h"

/**
 * flip_bits - Gets all  the number of bits that are needed to be
 *             flipped to get from one number to other.
 * @n: The number.
 * @m: The number to flip n to.
 *
 * Return: The number of bits to flip to get from n to m.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int xor = n ^ m, bits = 0;

	for (; xor > 0; xor >>= 1)
	{
		if (xor & 1)
			bits++;
	}

	return (bits);
}
