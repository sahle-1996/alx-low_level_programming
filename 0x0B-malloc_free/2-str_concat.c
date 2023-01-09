#include "main.h"
#include <stdlib.h>

/**
 * str_concat - Concatenates two strings
 * @s1: The string to be concatenated upon
 * @s2: The string to be concatenated to s1
 *
 * Return: If concatenation fails - NULL
 *         Otherwise - a pointer the newly-allocated space in memory
 *                     containing the concatenated strings
 */

char *str_concat(char *s1, char *s2)
{
	/*i is the argument string index*/
	/*j is the buffer index*/
	unsigned int i, len = 0, j = 0;
	char *buffer;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	for (i = 0; s1[i] || s2[i]; i++)
		len++;
	buffer = malloc(len * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	for (i = 0; s1[i]; i++)
		buffer[j++] = s1[i];
	for (i = 0; s2[i]; i++)
		buffer[j++] = s2[i];
	buffer[len] = '\0';
	return (buffer);
}
