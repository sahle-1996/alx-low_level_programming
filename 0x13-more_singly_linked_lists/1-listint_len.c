#include "lists.h"

/**
 * listint_len - Counts number of elements in
 *		 a linked listint_t list.
 * @B: Pointer to the head of the list.
 * Return: The number of elements.
 */
size_t listint_len(const listint_t *B)
{
	size_t node = 0;

	while (B)
	{
		node++;
		B = B->next;
	}
	return (node);
}

