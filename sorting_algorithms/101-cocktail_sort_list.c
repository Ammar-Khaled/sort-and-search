#include "sort.h"


/**
 * get_len - get list len
 * @list: list
 *
 * Return: length
 */
int get_len(listint_t **list)
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

/**
 * cocktail_sort_list - sorts a doubly linked list of integers ascendingly
 * using the Cocktail shaker sort algorithm
 * @list: list of integers
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped, len, start, end, i, *arr;
	listint_t *cur;

	len = get_len(list);
	arr = malloc(sizeof(int) * len);
	for (i = 0, cur = *list; i < len; i++, cur = cur->next)
		arr[i] = cur->n;
	swapped = 1;
	start = 0;
	end = len - 1;
	while (swapped)
	{
		swapped = 0;
		for (i = start; i < end; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				swap(arr + i, arr + i + 1);
				swapped = 1;
				print_array(arr, len);
			}
		}
		if (!swapped)
			break;
		end--;
		swapped = 0;
		for (i = end - 1; i >= start; i--)
		{
			if (arr[i] > arr[i + 1])
			{
				swap(arr + i, arr + i + 1);
				swapped = 1;
				print_array(arr, len);
			}
		}
		start++;
	}
	for (i = 0, cur = *list; i < len; i++, cur = cur->next)
		cur->n = arr[i];
	free(arr);
}
