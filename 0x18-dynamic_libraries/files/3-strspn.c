#include "main.h"

/**
 * _strspn - Gets the length of a prefix substring
 * @s: The string to be searched
 * @accept: The prefix to be measured
 *
 * Return: The number of bytes in s which
 *         consist only of bytes from accept
 */

unsigned int _strspn(char *s, char *accept)
{
	unsigned int i = 0, count = 0, j;
	char *super = s, *sub = accept;

	while (super[i])
	{
		for (j = 0; sub[j] != '\0'; j++)
		{
			if (super[i] == sub[j])
			{
				count++;
				break;
			}
			else if (sub[j + 1] == '\0')
				return (count);
		}
		i++;
	}
	return (count);
}
