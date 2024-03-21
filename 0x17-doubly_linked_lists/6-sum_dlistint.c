#include "lists.h"

/**
 * sum_dlistint - Returns the sum of all the data (n) of a doubly linked list
 * @head: Pointer to the head node of the doubly linked list
 *
 * Return: If the list is empty, returns 0
 */
int sum_dlistint(dlistint_t *head)
{
	dlistint_t *current_node = head;
	register int sum = 0;

	while (current_node)
	{
		sum += current_node->n;
		current_node = current_node->next;
	}
	return (sum);
}
