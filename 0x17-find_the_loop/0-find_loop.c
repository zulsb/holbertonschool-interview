#include "lists.h"

/**
 * find_listint_loop - Finds the loop in a linked list.
 * @head: Pointer to head of the list.
 * Return: The address of the node where the loop starts or
 * NULL if there is no loop.
 */

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *one, *two;

	if (!head)
		return (NULL);

	two = head->next;
	one = two->next;

	while (two && one && one->next)
	{
		if (two == head || one == head)
			return (head);
		if (two == one && one != head)
		{
			head = head->next;
			two = head;
			one = head;
		}
		two = two->next;
		one = one->next;
	}
	return (NULL);
}
