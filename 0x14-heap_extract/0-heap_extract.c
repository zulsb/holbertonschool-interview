#include "binary_trees.h"

/**
 * swap - Function taht sort the binary tree.
 * @aux: Is a pointer to the heap root.
 *
 * Return: The pointer to last node.
 **/

heap_t *swap(heap_t *aux)
{
	int value;

	while (aux->left || aux->right)
	{
		if (aux->right == NULL || aux->left->n > aux->right->n)
		{
			value = aux->n;
			aux->n = aux->left->n;
			aux->left->n = value;
			aux = aux->left;
		}
		else if (aux->left == NULL || aux->left->n < aux->right->n)
		{
			value = aux->n;
			aux->n = aux->right->n;
			aux->right->n = value;
			aux = aux->right;
		}
	}
	return (aux);
}

/**
 * heap_extract - Extracts the root node of a Max Binary Heap.
 * @root: Double pointer to the root node of the heap.
 *
 * Return: The value stored in the root node or 0 if fails.
 */

int heap_extract(heap_t **root)
{
	heap_t *node, *aux;
	size_t height;
	int value;

	if (root == NULL || *root == NULL)
		return (0);

	aux = *root;
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
