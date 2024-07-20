#include "search_algos.h"

/**
 * jump_search_list - searches for a value in a sorted list
 *                     using the Jump search algorithm
 * @list: pointer to the head of the list
 * @size: number of elements in the list
 * @value: the integer value to search for
 * Return: pointer to the node containing the value or NULL
 */
listint_t *jump_search_list(listint_t *list, size_t size, int value)
{
	size_t jump, idx;
	listint_t *start, *end;

	if (list == NULL || size == 0)
		return (NULL);

	start = list;
	jump = (size_t) sqrt(size);
	end = start;

	while (end && end->next && end->n < value)
	{
		for (idx = 0; idx < jump && end->next; idx++)
			end = end->next;
		
		printf("Value checked at index [%ld] = [%d]\n", end->index, end->n);

		if (end->n >= value || end->index >= size - 1)
			break;

		start = end;
	}

	printf("Value found between indexes [%ld] and [%ld]\n", start->index, end->index);

	while (start && start->index <= end->index)
	{
		printf("Value checked at index [%ld] = [%d]\n", start->index, start->n);
		if (start->n == value)
			return (start);
		start = start->next;
	}

	return (NULL);
}
