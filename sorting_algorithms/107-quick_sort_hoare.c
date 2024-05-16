#include "sort.h"

/**
 * hoare_partition - takes the last element as `pivot`,
 * places it at its correct position in sorted array,
 * such that all smaller elements are to the left of `pivot`
 * and all greater elements or equal are to the right of `pivot`
 * @array: array of integers
 * @low: the starting index
 * @high: the ending index
 * @size: size of the whole array => required for printing
 * Return: index of the `pivot` after placing in the right place
 */
int hoare_partition(int *array, int low, int high, size_t size)
{
	int i, j, pivot;

	/* Choosing the pivot */
	pivot = array[high];

	/* i maintains the smaller elements before it */
	i = low - 1;

	/* j maintains the bigger elements after it */
	j = high + 1;

	while (1)
	{

		/* Find leftmost element greater than or equal to the pivot */
		do {
			i++;
		} while (array[i] < pivot);

		/* Find rightmost element smaller than or equal to the pivot */
		do {
			j--;
		} while (array[j] > pivot);

		if (i >= j)
		{
			return (i);
		}

		swap(array + i, array + j);
		print_array(array, size);
	}
}

/**
 * _quick_sort_hoare - recursive function for the quick sort
 * @array: array of integers
 * @low: the starting index
 * @high: the ending index
 * @size: size of the whole array => required for printing
 */
void _quick_sort_hoare(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot_index = hoare_partition(array, low, high, size);
		/* array[pivot_index] is now at right place */

		/* quick_sort the left subarray */
		_quick_sort_hoare(array, low, pivot_index - 1, size);
		/* quick_sort the right subarray */
		_quick_sort_hoare(array, pivot_index, high, size);
	}
}

/**
 * quick_sort_hoare - implements QuickSort Algorithm
 * using Hoare partition scheme
 * @array: array of integers
 * @size: size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	_quick_sort_hoare(array, 0, size - 1, size);
}
