#ifndef _SEARCH_ALGOS_H_
#define _SEARCH_ALGOS_H_

#include <math.h>
#include "../sorting_algorithms/sort.h"

int linear_search(int *array, size_t size, int value);
int binary_search(int *array, size_t size, int value);
int jump_search(int *array, size_t size, int value);
int interpolation_search(int *array, size_t size, int value);
int exponential_search(int *array, size_t size, int value);
int advanced_binary(int *array, size_t size, int value);


void free_list(listint_t *list);
listint_t *create_singly_list(int *array, size_t size);
void print_singly_list(const listint_t *list);

listint_t *jump_list(listint_t *list, size_t size, int value);



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
	size_t index;
	struct skiplist_s *next;
	struct skiplist_s *express;
} skiplist_t;

void free_skiplist(skiplist_t *list);
void init_express(skiplist_t *list, size_t size);
skiplist_t *create_skiplist(int *array, size_t size);
void print_skiplist(const skiplist_t *list);

skiplist_t *linear_skip(skiplist_t *list, int value);

#endif
