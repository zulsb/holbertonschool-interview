#ifndef _BINARYS_TREES_H
#define _BINARYS_TREES_H

/**========================================================================*/
/**-LIBRARIES--------------------------------------------------------------*/
/**========================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**========================================================================*/
/**-STRUCTURES-------------------------------------------------------------*/
/**========================================================================*/
/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s heap_t;

/**========================================================================*/
/**-PROTOTYPES-------------------------------------------------------------*/
/**========================================================================*/

void binary_tree_print(const binary_tree_t *);

/** 0. Heap - Extract */
int heap_extract(heap_t **root);
heap_t *swap(heap_t *tmp);

#endif /* _BINARYS_TREES_H_ */
