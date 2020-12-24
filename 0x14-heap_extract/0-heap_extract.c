#include "binary_trees.h"

/**
 * swap - Function that sort the binary tree.
 * @tmp: Is a pointer to the heap root.
 *
 * Return: The pointer to last node.
 **/

heap_t *swap(heap_t *tmp)
{
	int value;

	while (tmp->left || tmp->right)
	{
		if (tmp->right == NULL || tmp->left->n > tmp->right->n)
		{
			value = tmp->n;
			tmp->n = tmp->left->n;
			tmp->left->n = value;
			tmp = tmp->left;
		}
		else if (tmp->left == NULL || tmp->left->n < tmp->right->n)
		{
			value = tmp->n;
			tmp->n = tmp->right->n;
			tmp->right->n = value;
			tmp = tmp->right;
		}
	}
	return (tmp);
}

/**
 * heap_extract - Extracts the root node of a Max Binary Heap.
 * @root: Double pointer to the root node of the heap.
 *
 * Return: The value stored in the root node or 0 if fails.
 */

int heap_extract(heap_t **root)
{
	heap_t *node, *aux = *root;
	size_t height;
	int value;

	if (root == NULL || *root == NULL)
		return (0);

	value = aux->n;
	if (!aux->left && !aux->right)
	{
		free(*root);
		return (value);
	}

	aux = swap(aux);
	aux->n = node->n;

	if (node->parent->right != NULL)
		node->parent->right = NULL;

	else
		node->parent->left = NULL;

	free(node);

	return (value);
}
