#include "binary_trees.h"

/**
 * height - Measures the height of a binary tree.
 * @tree: Pointer to tree.
 * Return: Height of binary tree.
 */

size_t height(const binary_tree_t *tree)
{
	size_t right = 0, left = 0;

	if (tree == NULL)
		return (0);
	if (tree->right)
		right += height(tree->right) + 1;
	if (tree->left)
		left += height(tree->left) + 1;
	return (right < left ? left : right);
}

/**
 * is_avl - Checks if a binary tree is an AVL.
 * @tree: Pointer to tree.
 * @max: Max limit.
 * @min: Min limit.
 * Return: 1 if is avl tree else 0.
 */

size_t is_avl(const binary_tree_t *tree, int max, int min)
{
	size_t l = height(tree->left);
	size_t r = height(tree->right);

	if (tree == NULL)
		return (0);
	l = l > r ? l - r : r - l;
	if (l > 0)
		return (0);
	l = 1;
	r = 1;
	if (tree->left)
	{
		if ((tree->left->n >= tree->n) || (tree->left->n <= min))
			return (0);
		l = is_avl(tree->left, tree->n, min);
	}
	if (tree->right)
	{
		if ((tree->right->n <= tree->n) || (tree->right->n >= max))
			return (0);
		r = is_avl(tree->right, max, tree->n);
	}
	return (r == 1 && l == 1);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree.
 * @tree: Pointer to the root node of the tree to check.
 * Return: 1 if tree is a valid AVL Tree and 0 otherwise.
 */

int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_avl(tree, INT_MAX, INT_MIN));
}
