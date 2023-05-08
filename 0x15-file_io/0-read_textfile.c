#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <fcntl.h>
#include "main.h"

/**
 * read_textfile - for reading a text file and prited to standard outpust.
 * @filename: text file.
 * @letters: size of text file.
 *
 * Return: r_num || 0
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int file, r_num, file_write;
	char *buf;

	buf = malloc(sizeof(*buf) * (letters + 1));
	if (filename == NULL || buf == NULL)
	{
		free(buf);
		return (0);
	}
	file = open(filename, O_RDONLY);
	if (file == -1)
		return (0);
	r_num = read(file, buf, letters);
	if (r_num == -1)
		return (0);
	buf[r_num] = '\0';
	file_write = write(STDOUT_FILENO, buf, r_num);
	if (file_write == -1)
		return (0);
	free(buf);
	close(file);
	return (r_num);
}
