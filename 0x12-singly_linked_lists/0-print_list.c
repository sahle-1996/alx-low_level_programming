#include "lists.h"
#include <stdio.h>

/**
 * print_list - Prints elements of all list_t list
 * @h: Pointer to a struct of type list_t
 *
 * Return: The number of nodes in h
 */
size_t print_list(const list_t *h)
{
	size_t nodes = 0;

	while (a)
	{
		if (a->str == NULL)
			printf("[0] (nil)\n");
		else
			printf("[%d] %s\n", a->len, a->str);
		nodes++;
		a = a->next;
	}
	return (nodes);
}
