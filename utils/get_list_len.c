#include "../sorting_algorithms/sort.h"

/**
 * get_len - get list len
 * @list: list
 *
 * Return: length
 */
int get_list_len(listint_t **list)
{
	listint_t *cur;
	int len;

	cur = *list;
	len = 0;
	while (cur)
	{
		len++;
		cur = cur->next;
	}

	return (len);
}
