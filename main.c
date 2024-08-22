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
    int *array, value, index, n;
    listint_t *list, *slist, *jump_res;
    skiplist_t *skip_list, *skip_res;
    char c;
    FILE *fptr;
    char complexity[100];

    printf("%s\n", "Welcome to sort and search!");
    printf("%s\n", "###########################");

    do
    {
        do
        {
            printf("%s", "Enter a positive number of integers to sort: ");
            scanf("%d", &n);
        } while (n <= 0);
        size = (size_t)n;
        array = malloc(size * sizeof(int));
        if (!array) {
            perror("malloc couldn't allocate memory for the array\n");
            return (EXIT_FAILURE);
        }

        printf("%s", "Enter your integers separated by space: ");
        for (i = 0; i < size; i++) {
            scanf("%d", &array[i]);
        }

        printf("%s\n", "Choose a sorting algorithm:");
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
                fptr = fopen("sorting_algorithms/O/bubble_sort.txt", "r");
                break;
            case 1:
                printf("%s\n", "using Insertion Sort:");
                fptr = fopen("sorting_algorithms/O/insertion_sort_list.txt", "r");
                list = create_doubly_listint(array, size);
                insertion_sort_list(&list);
                break;
            case 2:
                printf("%s\n", "using Selection Sort:");
                fptr = fopen("sorting_algorithms/O/2-selection_sort.txt", "r");
                selection_sort(array, size);
                break;
            case 3:
                printf("%s\n", "using Quick Sort (Lomuto Partition Scheme):");
                fptr = fopen("sorting_algorithms/quick_sort_lomuto.c", "r");
                quick_sort_lomuto(array, size);
                break;
            case 4:
                printf("%s\n", "using Shell Sort:");
                fptr = fopen("sorting_algorithms/O/shell_sort.txt", "r");
                shell_sort(array, size);
                break;
            case 5:
                printf("%s\n", "using Cocktail Shaker Sort:");
                fptr = fopen("sorting_algorithms/O/sorting_algorithms/cocktail_sort_list.c", "r");
                cocktail_sort(array, size);
                break;
            case 6:
                printf("%s\n", "using Counting Sort:");
                fptr = fopen("sorting_algorithms/O/counting_sort.txt", "r");
                counting_sort(array, size);
                break;
            case 7:
                printf("%s\n", "using Merge Sort:");
                fptr = fopen("sorting_algorithms/O/merge_sort.txt", "r");
                merge_sort(array, size);
                break;
            case 8:
                printf("%s\n", "using Heap Sort:");
                fptr = fopen("sorting_algorithms/O/heap_sort.txt", "r");
                heap_sort(array, size);
                break;
            case 9:
                printf("%s\n", "using Radix Sort:");
                fptr = fopen("sorting_algorithms/O/radix_sort.txt", "r");
                radix_sort(array, size);
                break;
            case 10:
                printf("%s\n", "using Bitonic Sort:");
                fptr = fopen("sorting_algorithms/O/bitonic_sort.txt", "r");
                bitonic_sort(array, size);
                break;
            case 11:
                printf("%s\n", "using Quick Sort (Hoare Partition Scheme):");
                fptr = fopen("sorting_algorithms/O/quick_sort_hoare.txt", "r");
                quick_sort_hoare(array, size);
                break;
            default:
                printf("%s\n", "Invalid choice. using Bubble Sort by default:");
                bubble_sort(array, size);
                break;
        }
        printf("%s", "Sorted array is: ");
        print_array(array, size);
        fgets(complexity, 100, fptr);
        printf("Time complexity: %s\n", complexity);
        fclose(fptr);

        printf("%s\n", "Enter a value to search for in the sorted array: ");
        scanf("%d", &value);

        printf("%s\n", "Choose a searching algorithm:");
        printf("%s\n", "0. Linear Search");
        printf("%s\n", "1. Binary Search");
        printf("%s\n", "2. Jump Search");
        printf("%s\n", "3. Interpolation Search");
        printf("%s\n", "4. Exponential Search");
        printf("%s\n", "5. Advanced Binary Search");
        printf("%s\n", "6. Jump Search in a list");
        printf("%s\n", "7. Linear Skip");
        scanf("%lu", &i);

        printf("Searching for %d using ", value);
        switch (i)
        {
            case 0:
                printf("Linear Search:\n");
                fptr = fopen("searching_algorithms/O/linear.txt", "r");
                index = linear_search(array, size, value);
                if (index == -1)
                    printf("Value not found in the array\n");
                else
                    printf("Found %d at index: %d\n", value, index);
                break;
            case 1:
                printf("Binary Search:\n");
                fptr = fopen("searching_algorithms/O/binary.txt", "r");
                index = binary_search(array, size, value);
                if (index == -1)
                    printf("Value not found in the array\n");
                else
                    printf("Found %d at index: %d\n", value, index);
                break;
            case 2:
                printf("Jump Search:\n");
                fptr = fopen("searching_algorithms/O/jump.txt", "r");
                index = jump_search(array, size, value);
                if (index == -1)
                    printf("Value not found in the array\n");
                else
                    printf("Found %d at index: %d\n", value, index);
                break;
            case 3:
                printf("Interpolation Search:\n");
                fptr = fopen("searching_algorithms/O/interpolation.txt", "r");
                index = interpolation_search(array, size, value);
                if (index == -1)
                    printf("Value not found in the array\n");
                else
                    printf("Found %d at index: %d\n", value, index);
                break;
            case 4:
                printf("Exponential Search:\n");
                fptr = fopen("searching_algorithms/O/exponential.txt", "r");
                index = exponential_search(array, size, value);
                if (index == -1)
                    printf("Value not found in the array\n");
                else
                    printf("Found %d at index: %d\n", value, index);
                break;
            case 5:
                printf("Advanced Binary Search:\n");
                index = advanced_binary(array, size, value);
                if (index == -1)
                    printf("Value not found in the array\n");
                else
                    printf("Found %d at index: %d\n", value, index);
                break;
            case 6:
                printf("Jump Search in a list:\n");
                fptr = fopen("searching_algorithms/O/jump_list.txt", "r");
                slist = create_singly_list(array, size);
                jump_res = jump_list(slist, size, value);
                if (jump_res == NULL)
                    printf("Value not found in the list\n");
                else
                    printf("Found %d at index: %d\n", value, index);
                break;
            case 7:
                printf("Linear Skip:\n");
                skip_list = create_skiplist(array, size);
                skip_res = linear_skip(skip_list, value);
                if (skip_res == NULL)
                    printf("Value not found in the list\n");
                else
                    printf("Found %d at index: %d\n", value, index);
                break;
            default:
                break;
        }
        fgets(complexity, 100, fptr);
        printf("Time complexity: %s\n", complexity);
        fclose(fptr);

        while ((getchar()) != '\n'); /*clear inputr buffer*/
        printf("%s", "Do you want to try again? (y/n): ");
        scanf("%c", &c);
    } while (c == 'y' || c == 'Y');
    free(array);
    return (EXIT_SUCCESS);
}
