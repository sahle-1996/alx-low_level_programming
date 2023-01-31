#include "lists.h"

/**
 * find_listint_loop - Detects loop in a linked list.
 * @head: Pointer to head of the list.
 * Return: If there is a loop - pointer to
 *	   start of nodes.
 *	   Otherwise, if there is no loop - NULL.
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *fast, *slow;

	if (!head || !head->next)
		return (NULL);

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
				slow = slow->next;
				fast = fast->next;
			}
			head = slow;
			return (slow);
		}
	}
	return (NULL);
}
