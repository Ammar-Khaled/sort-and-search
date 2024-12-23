#ifndef _SEARCH_ALGOS_H_
#define _SEARCH_ALGOS_H_

#include <math.h>
#include "../sorting_algorithms/sort.h"

int (*get_search_function(char *option))(int *array, int size, int value);

int linear_search(int *array, int size, int value);
int binary_search(int *array, int size, int value);
int jump_search(int *array, int size, int value);
int interpolation_search(int *array, int size, int value);
int exponential_search(int *array, int size, int value);
int advanced_binary(int *array, int size, int value);


/**
 * struct skiplist_s - Singly linked list with an express lane
 *
 * @n: Integer
 * @index: Index of the node in the list
 * @next: Pointer to the next node
 * @express: Pointer to the next node in the express lane
 *
 * Description: singly linked list node structure with an express lane
 */
typedef struct skiplist_s
{
	int n;
	int index;
	struct skiplist_s *next;
	struct skiplist_s *express;
} skiplist_t;

void free_skiplist(skiplist_t *list);
void init_express(skiplist_t *list, int size);
skiplist_t *create_skiplist(int *array, int size);
void print_skiplist(const skiplist_t *list);

skiplist_t *linear_skip(skiplist_t *list, int value);

#endif
