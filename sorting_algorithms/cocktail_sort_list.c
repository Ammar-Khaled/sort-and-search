#include "sort.h"


/**
 * cocktail_sort - sorts a doubly linked list of integers ascendingly
 * using the Cocktail shaker sort algorithm
 * @list: list of integers
 */
void cocktail_sort(int *array, size_t size)
{
	int start, end, i, swapped;

	start = 0;
	end = size - 1;
	swapped = 1;
	while (swapped)
	{
		/*forward bubble sort*/
		swapped = 0;
		for (i = start; i < end; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap(array + i, array + i + 1);
				swapped = 1;
				print_array(array, size);
			}
		}

		if (!swapped)  /*if no swap happened, the array is sorted*/
			break;

		/*backword bubble sort*/
		end--;
		swapped = 0;
		for (i = end; i > start; i--)
		{
			if (array[i] < array[i - 1])
			{
				swap(array + i, array + i - 1);
				swapped = 1;
				print_array(array, size);
			}
		}
		start++;
	}
}
