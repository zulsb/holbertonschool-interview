#ifndef _BINARY_TREES_
#define _BINARY_TREES_

/**========================================================================*/
/**-LIBRARIES--------------------------------------------------------------*/
/**========================================================================*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/**========================================================================*/
/**-STRUCTURES-& DEFINITIONS-----------------------------------------------*/
/**========================================================================*/

/**
 * struct binary_tree_t - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_t
{
	int n;
	struct binary_tree_t *parent;
	struct binary_tree_t *left;
	struct binary_tree_t *right;
};
typedef struct binary_tree_t binary_tree_t;
typedef struct binary_tree_t heap_t;

typedef struct queue
{
	struct queue *next;
	struct binary_tree_t *element;
} queue;

/* Functions printing */
void binary_tree_print(const binary_tree_t *tree);

/** 0. Function that creates a binary tree node */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);

/** 1. Function that inserts a value into a Max Binary Heap */
heap_t *heap_insert(heap_t **root, int value);

#endif
