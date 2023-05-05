#include "main.h"
/**
 * binary_to_uint -converting a binary number in to an unsigned int.
 * @b: pointing to a string of 0 and 1 chars
 *
 * Return:converted number, or 0
 */
unsigned int binary_to_uint(const char *b)
{
	int a;
	unsigned int j;

	j = 0;
	if (!b)
		return (0);
	for (a = 0; b[a] != '\0'; a++)
	{
		if (b[a] != '0' && b[a] != '1')
			return (0);
	}
	for (a = 0; b[a] != '\0'; a++)
	{
		j = j << 1;
		if (b[a] == '1')
			j += 1;
	}
	return (j);
}
