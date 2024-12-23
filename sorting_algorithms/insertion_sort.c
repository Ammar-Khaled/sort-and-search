#include <stdlib.h>
#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort - implements Insertion Sort Algorithm
 * @array: pointer to the array to be sorted
 * @size: size of the array to be sorted
 */
void insertion_sort(int *array, int size)
{
    int i, j, tmp;

	for (i = 1; i < size; i++)
	{
		tmp = array[i];
		printf("key=%d => ", tmp);
		j = i - 1;
		while (j >= 0 && array[j] > tmp)
		{
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = tmp;
		print_array(array, size);
	}
}
