#include <stdlib.h>
#include <stdio.h>
#include "search_algos.h"

/**
 * linear_search - searches for a value in an array of integers
 * using the Linear search algorithm
 * @array: a pointer to the first element of the array to search in
 * @size: the number of elements in the array
 * @value: the value to search for
 *
 * Return: the first index where @value is located, or -1 otherwise
 */
int linear_search(int *array, int size, int value)
{
	int i;

	if (array == NULL)
		return (-1);

	for (i = 0; i < size; i++)
	{
		printf("Value checked array[%d] = [%d]\n", i, array[i]);
		if (value == array[i])
			return (i);
	}
	return (-1);
}
