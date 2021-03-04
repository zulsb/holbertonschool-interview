#ifndef DOUBLE_CIRCULAR_LISTS_H
#define DOUBLE_CIRCULAR_LISTS_H

/**========================================================================*/
/**-LIBRARIES--------------------------------------------------------------*/
/**========================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**========================================================================*/
/**-STRUCTURE--------------------------------------------------------------*/
/**========================================================================*/
/**
 * struct List - doubly linked list
 * @str: string - (malloc'ed string)
 * @prev: points to the previous node
 * @next: points to the next node
 *
 * Description: doubly linked list node structure
 * for Holberton project
 */
typedef struct List
{
	char *str;
	struct List *prev;
	struct List *next;
} List;

/**========================================================================*/
/**-PROTOTYPES-------------------------------------------------------------*/
/**========================================================================*/

/** 0. Add Nodes */
List *add_node_end(List **list, char *str);
List *add_node_begin(List **list, char *str);

#endif
