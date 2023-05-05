#include "main.h"

/**
 * get_endianness - checking the endianness
 *
 * Return: 0 if big endian, 1 if little endian
 */
int get_endianness(void)
{
	unsigned int x;
	char *b;

	x = 1;
	b = (char *) &x;

	return ((int)*b);
}
