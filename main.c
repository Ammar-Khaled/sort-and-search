#include <stdio.h>
#include <stdlib.h>
#include "sorting_algorithms/sort.h"
#include "searching_algorithms/search_algos.h"

void print_sorting_options(void);
void print_searching_options(void);

/**
 * main - Entry point
 * return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
*/
int main(void)
{
    int size, i;
    int *array, value, index;
    skiplist_t *skip_list, *skip_result;
    char c;
    FILE *fptr;
    char complexity[100];

    printf("%s\n", "Welcome to sort and search!");
    printf("%s\n", "###########################");

    do
    {
        do
        {
            printf("%s", "Enter the number of integers to sort: ");
            scanf("%d", &size);
            if (size <= 0) {
                printf("size of integers must be a positive number\n");
            }
        } while (size <= 0);

        array = malloc(size * sizeof(int));
        if (!array) {
            perror("malloc couldn't allocate memory for the array\n");
            return (EXIT_FAILURE);
        }

        printf("%s", "Enter your integers separated by space: ");
        for (i = 0; i < size; i++) {
            scanf("%d", &array[i]);
        }

    sorting:
        print_sorting_options();
        scanf("%d", &i);
        printf("%s", "Sorting...\n");
        switch (i) {
            case 0:
                bubble_sort(array, size);
                fptr = fopen("sorting_algorithms/O/bubble_sort.txt", "r");
                break;
            case 1:
                insertion_sort(array, size);
				fptr = fopen("sorting_algorithms/O/insertion_sort.txt", "r");
                break;
            case 2:
                selection_sort(array, size);
				fptr = fopen("sorting_algorithms/O/2-selection_sort.txt", "r");
                break;
            case 3:
				quick_sort_lomuto(array, size);
                fptr = fopen("sorting_algorithms/quick_sort_lomuto.c", "r");
                break;
            case 4:
                shell_sort(array, size);
				fptr = fopen("sorting_algorithms/O/shell_sort.txt", "r");
                break;
            case 5:
                cocktail_sort(array, size);
				fptr = fopen("sorting_algorithms/O/sorting_algorithms/cocktail_sort_list.c", "r");
                break;
            case 6:
				counting_sort(array, size);
                fptr = fopen("sorting_algorithms/O/counting_sort.txt", "r");
                break;
            case 7:
                merge_sort(array, size);
				fptr = fopen("sorting_algorithms/O/merge_sort.txt", "r");
                break;
            case 8:
                heap_sort(array, size);
				fptr = fopen("sorting_algorithms/O/heap_sort.txt", "r");
                break;
            case 9:
                radix_sort(array, size);
				fptr = fopen("sorting_algorithms/O/radix_sort.txt", "r");
                break;
            case 10:
                bitonic_sort(array, size);
				fptr = fopen("sorting_algorithms/O/bitonic_sort.txt", "r");
                break;
            case 11:
                quick_sort_hoare(array, size);
				fptr = fopen("sorting_algorithms/O/quick_sort_hoare.txt", "r");
                break;
            default:
                printf("Invalid option, try again\n");
                goto sorting;
        }
        printf("%s", "Sorted array is: ");
        print_array(array, size);
        fgets(complexity, 100, fptr);
        printf("Time complexity: %s", complexity);
		fgets(complexity, 100, fptr);
		printf("Space complexity: %s", complexity);
        fclose(fptr);

        printf("%s", "Enter a value to search for in the sorted array: ");
        scanf("%d", &value);

    searching:
        print_searching_options();
        scanf("%d", &i);
        printf("Searching...\n");
        switch (i)
        {
            case 0:
                fptr = fopen("searching_algorithms/O/linear.txt", "r");
                index = linear_search(array, size, value);
                if (index == -1)
                    printf("Value not found in the array\n");
                else
                    printf("Found %d at index: %d\n", value, index);
                break;
            case 1:
                fptr = fopen("searching_algorithms/O/binary.txt", "r");
                index = binary_search(array, size, value);
                if (index == -1)
                    printf("Value not found in the array\n");
                else
                    printf("Found %d at index: %d\n", value, index);
                break;
            case 2:
                fptr = fopen("searching_algorithms/O/jump.txt", "r");
                index = jump_search(array, size, value);
                if (index == -1)
                    printf("Value not found in the array\n");
                else
                    printf("Found %d at index: %d\n", value, index);
                break;
            case 3:
                fptr = fopen("searching_algorithms/O/interpolation.txt", "r");
                index = interpolation_search(array, size, value);
                if (index == -1)
                    printf("Value not found in the array\n");
                else
                    printf("Found %d at index: %d\n", value, index);
                break;
            case 4:
                fptr = fopen("searching_algorithms/O/exponential.txt", "r");
                index = exponential_search(array, size, value);
                if (index == -1)
                    printf("Value not found in the array\n");
                else
                    printf("Found %d at index: %d\n", value, index);
                break;
            case 5:
                fptr = fopen("searching_algorithms/O/advanced_binary.txt", "r");
                index = advanced_binary(array, size, value);
                if (index == -1)
                    printf("Value not found in the array\n");
                else
                    printf("Found %d at index: %d\n", value, index);
                break;
            case 6:
                skip_list = create_skiplist(array, size);
                skip_result = linear_skip(skip_list, value);
                if (skip_result == NULL)
                    printf("Value not found in the list\n");
                else
                    printf("Found %d at index: %d\n", value, skip_result->index);
                fptr = fopen("searching_algorithms/O/linear_skip.txt", "r");
                break;
            default:
                printf("Invalid option, try again\n");
                goto searching;
        }
        fgets(complexity, 100, fptr);
        printf("Time complexity: %s", complexity);
		fgets(complexity, 100, fptr);
		printf("Space complexity: %s", complexity);
        fclose(fptr);

        while ((getchar()) != '\n'); /*clear inputr buffer*/
        printf("%s", "Do you want to try again? (y/n): ");
        scanf("%c", &c);
    } while (c == 'y' || c == 'Y');
    free(array);
    return (EXIT_SUCCESS);
}


void print_sorting_options(void)
{
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
    printf("%s\n", "10. Bitonic Sort");
    printf("%s\n", "11. Quick Sort (Hoare Partition Scheme)");
}


void print_searching_options(void)
{
    printf("%s\n", "Choose a searching algorithm:");
    printf("%s\n", "0. Linear Search");
    printf("%s\n", "1. Binary Search");
    printf("%s\n", "2. Jump Search");
    printf("%s\n", "3. Interpolation Search");
    printf("%s\n", "4. Exponential Search");
    printf("%s\n", "5. Advanced Binary Search");
    printf("%s\n", "6. Linear Skip");
}
