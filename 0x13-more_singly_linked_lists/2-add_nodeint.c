#include "lists.h"

/**
 * add_nodeint - adds a new node at the beginning
 *		 of a listint_t list.
 * @head: Pointer to the head of the list.
 * @m: Integer for new node.
 * Return: Address of the new element for success.
 *	   otherwise NULL.
 */
listint_t *add_nodeint(listint_t **head, const int m)
{
	listint_t *p;

	p = malloc(sizeof(listint_t));

	if (p == NULL)
		return (NULL);

	p->m = m;
	p->next = *head;

	*head = p;

	return (p);
}
