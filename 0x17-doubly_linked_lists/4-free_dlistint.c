#include "lists.h"

/**
 * free_dlistint - Frees a doubly linked list
 * @head: Pointer to the head node of the doubly linked list
 *
 * Return: Nothing
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *temp_node;

	while (head)
	{
		temp_node = head;
		head = head->next;
		free(temp_node);
	}
}
