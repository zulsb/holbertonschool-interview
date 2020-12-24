#include "binary_trees.h"

/**
 * height - Function that measures the height.
 * @tree: pointer to the tree.
 *
 * Return: height of the tree.
 */
static size_t height(const binary_tree_t *tree)
{
	size_t left, right;

	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (0);
	left = 1 + height(tree->left);
	right = 1 + height(tree->right);
	return (right > left ? right : left);
}

/**
 * order - Fucntion that pre-order traversal.
 * @root: pointer to the root node of the tree to traverse.
 * @node: pointer to node in the tree.
 * @height: height of the tree.
 * @level: level of the tree.
 *
 * Return: Nothing.
 **/

void order(heap_t *root, heap_t **node, size_t height, size_t level)
{
	if (root != NULL)
	{
		if (height == level)
			*node = root;
		level++;
		if (root->left != NULL)
			order(root->left, node, height, level);
		if (root->right != NULL)
			order(root->right, node, height, level);
	}
}

/**
 * swap - sort the binary tree.
 * @aux: pointer to the heap root.
 * Return: pointer to last node.
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

	height = height(aux);
	order(aux, &node, height, 0);
	aux = swap(aux);
	aux->n = node->n;

	if (node->parent->right != NULL)
		node->parent->right = NULL;
	node->parent->left = NULL;

	free(node);
	return (value);
}
