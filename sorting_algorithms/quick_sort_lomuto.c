#include "sort.h"


/**
 * lomuto_partition - takes the last element as `pivot`,
 * places it at its correct position in sorted array,
 * such that all smaller elements are to the left of `pivot`
 * and all greater elements or equal are to the right of `pivot`
 * @array: array of integers
 * @low: the starting index
 * @high: the ending index
 * @size: size of the whole array => required for printing
 * Return: index of the `pivot` after placing in the right place
 */
int lomuto_partition(int *array, int low, int high, int size)
{
	int j;

	/* Choosing the pivot */
	int pivot = array[high];

	/* i indicates the index of the last smaller element */
	int i = low - 1;

	/* loop from low to high - 1 and compare with the pivot */
	for (j = low; j < high; ++j)
	{
		/* if current element is smaller than the pivot */
		if (array[j] <= pivot)
		{
			/* Increment index of last smaller element */
			i++;
			/* now i points to the first greater element */
			/* swap it with the current element */
			if (i != j)
			{
				swap(array + i, array + j);
				print_array(array, size);
			}
		}
	}
	/*
	 * putting pivot in right place
	 * by swapping it with the first greater element
	*/
	if (i + 1 != high)
	{
		swap(array + i + 1, array + high);
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * _quick_sort_lomuto - recursive function for the quick sort
 * @array: array of integers
 * @low: the starting index
 * @high: the ending index
 * @size: size of the whole array => required for printing
 */
void _quick_sort_lomuto(int *array, int low, int high, int size)
{
	if (low < high)
	{
		int pivot_index = lomuto_partition(array, low, high, size);
		/* array[pivot_index] is now at right place */

		/* quick_sort the left subarray */
		_quick_sort_lomuto(array, low, pivot_index - 1, size);
		/* quick_sort the right subarray */
		_quick_sort_lomuto(array, pivot_index + 1, high, size);
	}
}

/**
 * quick_sort_lomuto - implements QuickSort Algorithm
 * @array: array of integers
 * @size: size of the array
 */
void quick_sort_lomuto(int *array, int size)
{
	_quick_sort_lomuto(array, 0, size - 1, size);
}
