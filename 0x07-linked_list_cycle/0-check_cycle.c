#include "lists.h"

/**
 * check_cycle - Checks if a singly linked list has a cycle in it.
 * @list: Pointer to head of list.
 *
 * Return: 0 if there is no cycle or 1 if there is a cycle.
 */

int check_cycle(listint_t *list)
{
	listint_t *t = list, *h = list;

	while (h && h->next)
	{
		t = t->next;
		h = h->next->next;
		if (t == h)
			return (1);
	}
	return (0);
}
