#include <stdio.h>
#include <stdlib.h>
#include "sorting_algorithms/sort.h"
#include "searching_algorithms/search_algos.h"

/**
 * main - Entry point
 * return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
*/
int main(void)
{
    size_t size, i;
    int *array;
    listint_t *list;

    printf("%s\n", "Welcome to sort and search!");
    printf("%s\n", "###########################");
    printf("%s", "Enter the number of integers to sort: ");
    scanf("%lu", &size);
    array = malloc(size * sizeof(int));
    if (!array) {
        perror("malloc couldn't allocate memory for the array\n");
        return (EXIT_FAILURE);
    }

    printf("%s\n", "Enter your integers separated by space: ");
    for (i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    printf("%s\n", "Choose the sorting algorithm you want to use:");
    printf("%s\n", "0. Bubble Sort");
    printf("%s\n", "1. Insertion Sort");
    printf("%s\n", "2. Selection Sort");
    printf("%s\n", "3. Quick Sort (Lomuto Partition Scheme)");
    printf("%s\n", "4. Shell Sort");
    printf("%s\n", "5. Cocktail Shaker Sort in a list");
    printf("%s\n", "6. Counting Sort");
    printf("%s\n", "7. Merge Sort");
    printf("%s\n", "8. Heap Sort");
    printf("%s\n", "9. Radix Sort");
    printf("%s\n", "10. Bitoonic Sort");
    printf("%s\n", "11. Quick Sort (Hoare Partition Scheme)");
    scanf("%lu", &i);

    printf("%s", "Sorting the array ");
    switch (i) {
        case 0:
            printf("%s\n", "using Bubble Sort:");
            bubble_sort(array, size);
            break;
        case 1:
            printf("%s\n", "using Insertion Sort:");
            list = create_doubly_listint(array, size);
            insertion_sort_list(&list);
            break;
        case 2:
            printf("%s\n", "using Selection Sort:");
            selection_sort(array, size);
            break;
        case 3:
            printf("%s\n", "using Quick Sort (Lomuto Partition Scheme):");
            quick_sort_lomuto(array, size);
            break;
        case 4:
            printf("%s\n", "using Shell Sort:");
            shell_sort(array, size);
            break;
        case 5:
            printf("%s\n", "using Cocktail Shaker Sort in a list:");
            list = create_doubly_listint(array, size);
            cocktail_sort_list(&list);
            break;
        case 6:
            printf("%s\n", "using Counting Sort:");
            counting_sort(array, size);
            break;
        case 7:
            printf("%s\n", "using Merge Sort:");
            merge_sort(array, size);
            break;
        case 8:
            printf("%s\n", "using Heap Sort:");
            heap_sort(array, size);
            break;
        case 9:
            printf("%s\n", "using Radix Sort:");
            radix_sort(array, size);
            break;
        case 10:
            printf("%s\n", "using Bitonic Sort:");
            bitonic_sort(array, size);
            break;
        case 11:
            printf("%s\n", "using Quick Sort (Hoare Partition Scheme):");
            quick_sort_hoare(array, size);
            break;
        default:
            printf("%s\n", "Invalid choice. using Bubble Sort by default:");
            bubble_sort(array, size);
            break;
    }
    printf("%s", "Sorted array: ");
    print_array(array, size);
    return (EXIT_SUCCESS);
}
