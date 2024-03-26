#include "main.h"

/**
 * _strchr - Locates a character in a string
 * @s: The string to be searched
 * @c: The character to be located
 *
 * Return: If c is found - a pointer to the first occurence
 *         If c is not found - NULL
 */

char *_strchr(char *s, char c)
{
	int i = 0, len = 0;

	while (s[i++])
		len++;

	for (i = 0; i < (len + 1); i++)
	{
		if (s[i] == c)
			return (s + i);
	}
	return ('\0');
}
