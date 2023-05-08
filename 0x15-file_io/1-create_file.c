#include <unistd.h>
#include <stddef.h>
#include <fcntl.h>
#include "main.h"


/**
 * _strlen - figures out the length of a string.
 * @str: string parameter.
 *
 * Return: len
 */

int _strlen(char *str);

/**
 * create_file - a function creaating a file.
 * @filename: Name of text file.
 * @text_content: string.
 *
 * Return: 1 (Success) || -1 (Failure)
 */

int create_file(const char *filename, char *text_content)
{
	int file, write_file;

	if (filename == NULL)
		return (-1);
	file = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	if (file == -1)
		return (-1);
	if (text_content != NULL)
	{
		write_file = write(file, text_content, _strlen(text_content));
		if (write_file == -1)
		{
			close(file);
			return (-1);
		}
		close(file);
		return (1);
	}
	close(file);
	return (1);
}

/**
 * _strlen - figurer out the length of file.
 * @str: string parameter.
 *
 * Return: len
 */

int _strlen(char *str)
{
	int len = 0;

	while (str[len] != '\0')
		len++;
	return (len);
}
