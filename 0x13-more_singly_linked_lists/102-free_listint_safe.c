#include "lists.h"

/**
 * loop_flag2 - Detects loop in a linked list.
 * @head: Pointer to head of the list.
 * Return: If there is a loop - number of nodes.
 *	   If there is no loop - 0.
 */
size_t loop_flag2(listint_t *head)
{
	listint_t *fast, *slow;
	size_t node = 0;

	if (!head || !head->next)
		return (0);

	slow = head;
	fast = head;

	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
		{
			slow = head;
			while (slow != fast)
			{
				node++;
				slow = slow->next;
				fast = fast->next;
			}

			fast = fast->next;
			while (slow != fast)
			{
				node++;
				fast = fast->next;
			}
			return (++node);
		}
	}
	return (0);
}

/**
 * free_listint_safe - Frees a listint_t list safely (ie.
 *                     can free lists containing loops)
 * @h: A pointer to the address of
 *     the head of the listint_t list.
 *
 * Return: The size of the list that was freed.
 *
 * Description: The function sets the head to NULL.
 */
size_t free_listint_safe(listint_t **h)
{
	size_t node, i = 0;
	listint_t *tmp;

	if (h == NULL)
		return (0);

	node = loop_flag(*h);

	if (node == 0)
	{
		while (*h)
		{
			node++;
			tmp = (*h)->next;
			free(*h);
			*h = tmp;
		}
		*h = NULL;
	}

	else
	{
		while (i < node)
		{
			tmp = (*h)->next;
			free(*h);
			*h = tmp;
			i++;
		}
		*h = NULL;
	}

	h = NULL;

	return (node);
}
