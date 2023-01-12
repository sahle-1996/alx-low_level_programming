#include "main.h"
#include <stdlib.h>

/**
 * string_nconcat - Concatenates two strings using at
 *                  most an inputted number of bytes.
 * @s1: The first string
 * @s2: The second string
 * @n: The maximum number of bytes of s2 to concatenate to s1
 *
 * Return: If the function fails - NULL
 *         Otherwise - a pointer to the concatenated space in memory
 */

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int i, index = 0, len = n;
	char *str;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	for (i = 0; s1[i]; i++)
		len++;

	str = malloc((len + 1) * sizeof(char));

	if (str == NULL)
		return (NULL);

	for (i = 0; s1[i]; i++)
		str[index++] = s1[i];

	for (i = 0; i < n && s2[i]; i++)
		str[index++] = s2[i];

	str[index] = '\0';

	return (str);
}
