#include "lists.h"

/**
 * get_dnodeint_at_index - Returns the nth node of a doubly linked list
 * @head: Pointer to the head node of the doubly linked list
 * @index: Index of the node to retrieve
 *
 * Return: If the node does not exist, returns NULL
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *current_node = head;

	while (current_node && index)
	{
		index--;
		current_node = current_node->next;
	}
	return (current_node);
}
