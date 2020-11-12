#ifndef _SEARCH_H_
#define _SEARCH_H_

/**========================================================================*/
/**-LIBRARIES--------------------------------------------------------------*/
/**========================================================================*/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/**========================================================================*/
/**-STRUCTURES-------------------------------------------------------------*/
/**========================================================================*/
/**
 * struct skiplist_s - Singly linked list with an express lane
 *
 * @n: Integer
 * @index: Index of the node in the list
 * @next: Pointer to the next node
 * @express: Pointer to the next node in the express lane
 *
 * Description: singly linked list node structure with an express lane
 * for Holberton project
 */
typedef struct skiplist_s
{
	int n;
	size_t index;
	struct skiplist_s *next;
	struct skiplist_s *express;
} skiplist_t;

/**========================================================================*/
/**-PROTOTYPES-------------------------------------------------------------*/
/**========================================================================*/
skiplist_t *create_skiplist(int *array, size_t size);
void print_skiplist(const skiplist_t *list);
void free_skiplist(skiplist_t *list);

/** 0. Linear search in a skip list */
skiplist_t *linear_skip(skiplist_t *list, int value);

#endif /* _SEARCH_H_ */
