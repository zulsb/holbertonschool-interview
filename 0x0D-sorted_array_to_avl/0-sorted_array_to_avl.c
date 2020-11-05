#include "binary_trees.h"

/**
 * sorted_array_to_avl - Build an AVL tree from array.
 * @array: Pointer to the first element pointer array.
 * @size: Number of element in the array.
 *
 * Return: Pointer to the root node of the created AVL tree or NULL on failure.
*/

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *tree;

	if (size == 0 || !array)
		return (NULL);

	tree = builder(NULL, array, 0, size - 1);

	return (tree);
}


/**
 *builder - Build in fact an AVL tree.
 * @parent: Parent pointer.
 * @array: Array pointer.
 * @start: Index to start.
 * @end: Index to end.
 *
 * Return: Pointer to the root node of the created AVL tree or NULL on failure.
*/

avl_t *builder(avl_t *parent, int *array, size_t start, size_t end)
{
	avl_t *node;
	size_t i = (start + end) / 2;

	node = malloc(sizeof(avl_t));

	if (!node)
		return (NULL);

	node->n = array[i];
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;

	if (i != start)
		node->left = builder(node, array, start, i - 1);
	if (i != end)
		node->right = builder(node, array, i + 1, end);
	return (node);
}
