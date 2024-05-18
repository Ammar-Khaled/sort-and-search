#include <stdlib.h>
#include "../searching_algorithms/search_algos.h"

/**
 * free_list - Deallocates a singly linked list
 *
 * @list: Pointer to the linked list to be freed
 */
void free_list(singly_listint_t *list)
{
	singly_listint_t *node;

	if (list)
	{
		node = list->next;
		free(list);
		free_list(node);
	}
}
