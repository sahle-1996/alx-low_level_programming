#include "lists.h"

/**
 * insert_dnodeint_at_index - Inserts a new node at a given position
 * @h: Pointer to the head node of the doubly linked list
 * @idx: Index where the new node should be added (starting from 0)
 * @n: Value of the new node
 *
 * Return: The address of the new node, or NULL if it failed
 *         If it's not possible to add the new node at index idx, do not
 *         add the new node and return NULL
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *tmp = *h, *new;

	if (idx == 0)
		return (add_dnodeint(h, n));

	for (; idx != 1; idx--)
	{
		tmp = tmp->next;
		if (!tmp)
			return (NULL);
	}

	if (!tmp->next)
		return (add_dnodeint_end(h, n));

	new = malloc(sizeof(dlistint_t));
	if (!new)
		return (NULL);

	new->n = n;
	new->prev = tmp;
	new->next = tmp->next;
	tmp->next->prev = new;
	tmp->next = new;

	return (new);
}
