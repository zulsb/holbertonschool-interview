#include "lists.h"

/**
 * reverse - Function that reverse the list.
 * @head: Pointer to pointer of first node of listint_t list.
 *
 * Return: nothing.
*/

void reverse(listint_t **head)
{
	listint_t *prev = NULL, *ptr = *head, *aux;

	while (ptr)
	{
		aux = ptr->next;
		ptr->next = prev;
		prev = ptr;
		ptr = aux;
	}
	*head = prev;
}

/**
 * is_palindrome - Function in C that checks if a singly linked
 * list is a palindrome.
 * @head: Pointer to pointer of first node of listint_t list.
 *
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome.
*/

int is_palindrome(listint_t **head)
{
	listint_t *first, *second, *mid = NULL;

	first = second = *head;

	if (head == NULL || *head == NULL)
		return (1);

	while (second)
	{
		second = second->next;
		if (second)
		{
			second = second->next;
			first = first->next;
		}
	}
	mid = first;

	reverse(&(mid->next));

	first = *head;
	second = mid->next;

	while (second != NULL)
	{
		if (first->n != second->n)
			return (0);
		first = first->next;
		second = second->next;
	}
	return (1);
}
