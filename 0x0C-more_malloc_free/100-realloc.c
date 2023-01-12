nclude "main.h"
#include <stdlib.h>

/**
 * _realloc - Reallocates a memory block using malloc and free
 * @ptr: A pointer to the memory previously allocated
 * @old_size: The size in bytes of the allocated space for ptr
 * @new_size: The size in bytes for the new memory block
 * Return: If new_size == old_size - ptr
 *         If new_size == 0 and ptr is not NULL - NULL
 *         Otherwise - a pointer to the reallocated memory block
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *mem;
	char *cpy1, *cpy2;
	unsigned int i;

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
	{
		mem = malloc(new_size);
		if (mem == NULL)
			return (NULL);
		return (mem);
	}

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	cpy1 = ptr;

	mem = malloc(sizeof(*cpy1) * new_size);
	if (mem == NULL)
	{
		free(ptr);
		return (NULL);
	}

	cpy2 = mem;

	for (i = 0; i < new_size && i < old_size; i++)
		*(cpy2 + i) = *cpy1++;

	free(ptr);
	return (mem);
}
