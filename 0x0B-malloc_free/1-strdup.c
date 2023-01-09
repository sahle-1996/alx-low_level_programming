#include "main.h"
#include <stdlib.h>

/**
 * _strdup - Returns a pointer to a newly-allocated space in memory
 *           containing a copy of the string given as parameter
 * @str: The string to be copied
 *
 * Return: If str == NULL or insufficient memory is available - NULL.
 *         Otherwise - a pointer to the duplicated string
 */

char *_strdup(char *str)
{
	int i, len;
	char *s;

	if (str == NULL)
		return (NULL);
	for (i = 0; str[i]; i++)
		len++;
	s = malloc((len + 1) * sizeof(char));
	if (s == NULL)
		return (NULL);
	for (i = 0; str[i]; i++)
		s[i] = str[i];
	s[len] = '\0';
	return (s);
}
