#include "sort.h"
#include <string.h>

/**
 * bitonic_merge - bitonic_merge
 * @arr: array
 * @low: low index
 * @cnt: count
 * @dir: direction
 * @size: size
 */
void bitonic_merge(int *arr, int low, int cnt, int dir, int size)
{
	int k, i;
	char *direction;

	if (dir == 1)
	{
		direction = "UP";
	}
	else
	{
		direction = "DOWN";
	}

	if (cnt > 1)
	{
		k = cnt / 2;


		for (i = 0; i < low + k; i++)
		{
			if (dir == (arr[i] > arr[i + k]))
			{
				swap(arr + i, arr + i + k);
			}
		}

		bitonic_merge(arr, low, k, dir, size);
		bitonic_merge(arr, low + k, k, dir, size);


		printf("Result [%i/%i] (%s):\n", cnt, size, direction);
		print_array(arr, cnt);

	}
}

/**
 * _bitonic_sort - _bitonic_sort
 * @arr: array
 * @low: low index
 * @cnt: count
 * @dir: direction
 * @size: size
 */
void _bitonic_sort(int *arr, int low, int cnt, int dir, int size)
{
	int k;

	char *direction;

	if (dir == 1)
	{
		direction = "UP";
	}
	else
	{
		direction = "DOWN";
	}

	if (cnt > 1)
	{
		k = cnt / 2;
		printf("Merging [%i/%i] (%s):\n", cnt, size, direction);
		print_array(arr, cnt);

		_bitonic_sort(arr, low, k, 1, size);
		_bitonic_sort(arr, low + k, k, 0, size);
		bitonic_merge(arr, low, cnt, dir, size);
	}
}

/**
 * bitonic_sort - bitonic_sort
 * @array: array
 * @size: size
 */
void bitonic_sort(int *array, size_t size)
{
	_bitonic_sort(array, 0, size, 1, size);
}
