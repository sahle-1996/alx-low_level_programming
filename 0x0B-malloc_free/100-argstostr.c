#include "main.h"
#include <stdlib.h>

/**
 * argstostr - Concatenates all arguments of the program into a string;
 *             arguments are separated by a new line in the string
 * @ac: The number of arguments passed to the program
 * @av: An array of pointers to the arguments
 *
 * Return: If ac == 0, av == NULL, or the function fails - NULL.
 *         Otherwise - a pointer to the new string
 */
char *argstostr(int ac, char **av)
{
	char *str;
	int i, j, concat_index, len = ac;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j]; j++)
			len++;
	}

	str = malloc(sizeof(char) * len + 1);

	if (str == NULL)
		return (NULL);

	concat_index = 0;

	for (i = 0; av[i]; i++)
	{
		for (j = 0; av[i][j]; j++)
			str[concat_index++] = av[i][j];
		str[concat_index++] = '\n';
	}

	str[len] = '\0';

	return (str);
}