#include "lists.h"

/**
 * add_nodeint_end - Adds a new node at the end
 *		     of a listint_t list.
 * @head: Pointer to the head of the list
 * @m: Integer for the new node
 * Return: Pointer to the new node for success
 *	   Otherwise NULL.
 */
listint_t *add_nodeint_end(listint_t **head, const int m)
{
	listint_t *p, *tmp;

	p = malloc(sizeof(listint_t));
	if (p == NULL)
		return (NULL);

	p->m = m;
	p->next = NULL;

	if (*head == NULL)
		*head = p;
	else
	{
		tmp = *head;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		tmp->next = p;
	}
	return (p);
}
