#include <stdio.h>
#include <stdlib.h>
#include "sorting_algorithms/sort.h"
#include "searching_algorithms/search_algos.h"


int main(void)
{
    int array[] = {0, 4, 5, 1, 2};
    size_t size = sizeof(array) / sizeof(array[0]);
    bubble_sort(array, size);
    return (0);
}
