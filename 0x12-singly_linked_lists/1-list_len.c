#include "lists.h"
/**
 * list_len - returns then number of elements in a list
 * @a: singly linked list
 * Return: number of elements in the list
 */

size_t list_len(const list_t *a)
{
	size_t nelem;

	nelem = 0;
	while (a != NULL)
	{
		a = a->next;
		nelem++;
	}
	return (nelem);
}
