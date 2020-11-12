#include "search.h"

/**
 * linear_skip -  Function that searches for a value in a sorted
 *                skip list of integers.
 * @list: Is a pointer to the head of the skip list to search.
 * @value: Value to search.
 *
 * Return: pointer on the first node or NULL.
 */

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *NodeExp, *prevNode = list;

	if (list == NULL)
		return (NULL);

	NodeExp = list->express;
	for (; NodeExp; NodeExp = NodeExp->express)
	{
		printf("Value checked at index [%lu] = [%d]\n", NodeExp->index, NodeExp->n);
		if (NodeExp->n >= value)
			break;
		prevNode = NodeExp;
		if (NodeExp->express == NULL)
		{
			while (NodeExp->next)
				NodeExp = NodeExp->next;
			break;
		}
		NodeExp = NodeExp->express;
	}
	printf("Value found between indexes [%lu] and [%lu]\n",
		prevNode->index, NodeExp->index);
	while (prevNode && prevNode->index <= NodeExp->index)
	{
		printf("Value checked at index [%lu] = [%d]\n",
			prevNode->index, prevNode->n);
		if (prevNode->n == value)
			return (prevNode);
		prevNode = prevNode->next;
	}
	return (NULL);
}
