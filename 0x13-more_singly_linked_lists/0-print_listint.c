#include "lists.h"

/**
 * print_listint - prints all the elements of a listint_t list
 * @A: Pointer to head of the list
 * Return: Number of nodes
 */
size_t print_listint(const listint_t *A)
{
	size_t node = 0;

	while (A)
	{
		printf("%d\n", A->n);
		node++;
		A = A->next;
	}
	return (node);
}
