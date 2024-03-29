#include "lists.h"

/**
 * pop_listint - Deletes the head node of a listint_t list.
 * @head: A pointer to the address of the
 *        head of the listint_t list.
 * Return: If the linked list is empty - 0.
 *         Otherwise - The head node's data (m).
 */
int pop_listint(listint_t **head)
{
	listint_t *tmp;
	int m;

	if (*head == NULL)
		return (0);

	tmp = (*head)->next;
	m = (*head)->n;
	free(*head);

	*head = tmp;

	return (m);
}
