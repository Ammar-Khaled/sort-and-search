#include "sort.h"
#include <stdio.h>

/**
 * bubble_sort - implements Bubble Sort Algorithm
 * @array: pointer to the array to be sorted
 * @size: size of the array to be sorted
 */
void bubble_sort(int *array, int size)
{
	int swapped = 0, i, j;

	/* loop n-1 iterations */
	for (i = 0; i < size; ++i)
	{

		/* the last i elements are already in place */
		for (j = 0; j < size - 1 - i; ++j)
		{
			if (array[j] > array[j + 1])
			{
				/* Bubble the greater element forward */
				swap(array + j, array + j + 1);
				swapped = 1;
				print_array(array, size);
			}
		}
		/* An optimization for the best case */
		if (swapped == 0) /* then it's sorted now */
			break;
	}
}
