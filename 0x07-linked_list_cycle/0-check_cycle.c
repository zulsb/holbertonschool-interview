#include "lists.h"

/**
 * check_cycle - Checks if a singly linked list has a cycle in it.
 * @list: Pointer to head of list.
 *
 * Return: 0 if there is no cycle or 1 if there is a cycle.
 */

int check_cycle(listint_t *list)
{
	listint_t *h = list, *l = list;

	while (l && l->next)
	{
		h = h->next;
		l = l->next->next;
		if (h == l)
			return (1);
	}
	return (0);
}
