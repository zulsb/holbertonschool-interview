#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - Inserts a number into a sorted singly linked list.
 * @head: Pointer to pointer of first node to the list.
 * @number: Integer in new nodo.
 *
 * Return: The address of the new node, or NULL if it failed.
*/

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new_nodo, *aux;

	aux = *head;

	new_nodo = malloc(sizeof(listint_t));
	if (new_nodo == NULL)
		return (NULL);

	new_nodo->n = number;
	new_nodo->next = NULL;

	if (*head == NULL)
		*head = new_nodo;
	else
	{
		while (aux->next != NULL && aux->next->n < new_nodo->n)
		{
			aux = aux->next;
		}
		new_nodo->next = aux->next;
		aux->next = new_nodo;
	}

	return (new_nodo);
}
