#include "search_algos.h"

/**
 * linear_skip_search - searches for a value in a skip list
 * @list: pointer to the head of the skip list
 * @value: the value to search for
 * Return: pointer to the node containing the value or NULL
 */
skiplist_t *linear_skip_search(skiplist_t *list, int value)
{
	skiplist_t *current, *end;

	if (list == NULL)
		return (NULL);

	current = list;
	while (current->express && current->express->n < value)
	{
		end = current;
		current = current->express;
		printf("Value checked at index [%d] = [%d]\n",
		       (int)current->index, current->n);
	}

	if (current->express == NULL)
	{
		end = current;
		while (end->next)
			end = end->next;
	}

	printf("Value found between indexes [%d] and [%d]\n",
	       (int)current->index, (int)end->index);

	while (list != end->next)
	{
		printf("Value checked at index [%d] = [%d]\n",
		       (int)list->index, list->n);
		if (list->n == value)
			return (list);
		list = list->next;
	}

	return (NULL);
}
