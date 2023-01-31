#include "lists.h"

/**
 * free_listint2 - frees a linked list
 * @first: first of a list.
 *
 * Return: no return.
 */
void free_listint2(listint_t **first)
{
	listint_t *temp;
	listint_t *curr;

	if (first != NULL)
	{
		curr = *first;
		while ((temp = curr) != NULL)
		{
			curr = curr->next;
			free(temp);
		}
		*first = NULL;
	}
}
