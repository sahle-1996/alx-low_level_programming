#include "main.h"

/**
 * _strstr - locates a substring
 * @haystack: string to be searched
 * @needle: string to be found
 * Return: If the string is found - a
 *		pointer to the beginning of
 *		the located substring
 *	If the substring is not found - NULL
 */

char *_strstr(char *haystack, char *needle)
{
	int i;
	char *s = haystack, *t = needle;

	if (*t == '\0')
		return (s);
	while (*s)
	{
		i = 0;

		if (s[i] == t[i])
		{
			while (s[i] == t[i])
			{
				if (t[i + 1] == '\0')
					return (s);
				i++;
			}
		}
		s++;
	}
	return ('\0');
}
