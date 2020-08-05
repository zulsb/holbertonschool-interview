#include "binary_trees.h"

/**
 * heap_insert - Insert a value into a Max Binary Heap.
 * @root: Is a double pointer to the root node of the Heap.
 * @value: Is the value of the new node.
 *
 * Return: A pointer to the new node or NULL on failure.
*/

heap_t *heap_insert(heap_t **root, int value)
{

	heap_t *current_node;

	current_node = binary_tree_node(*root, value);

	if (*root == NULL)
		*root = current_node;
	else
	{
		if (current_node->left == NULL && current_node->parent->n < current_node->n)
		{
			current_node->parent->left = current_node;
			current_node->parent->n = current_node->n;
			current_node = current_node->parent;
		}
		else
			current_node->parent->right = current_node;
	}
	return (current_node);
}
