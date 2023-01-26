#include "lists.h"

/**
 * free_list - frees a list
 * @first: head of the linked list.
 * Return: no return.
 */

void free_list(list_t *first)
{
	list_t *current;

	while ((current = first) != NULL)
	{
		first = first->next;
		free(current->str);
		free(current);
	}
}
