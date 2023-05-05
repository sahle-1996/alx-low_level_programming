#include "main.h"

/**
 * get_endianness - endianness checking.
 *
 * Return: 0 - If big-endian.
 *         1 - If little-endian.
 */
int get_endianness(void)
{
	int num = 1;
	char *c = (char *)&num;

	if (*c)
		return (1);
	return (0);
}
