#ifndef _SORT_H_
#define _SORT_H_

#include <stdlib.h>
#include <stdio.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	int n;
	size_t index;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* utils */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void swap(int *a, int *b);
int get_list_len(listint_t **list);

void bubble_sort(int *array, size_t size);

void insertion_sort_list(listint_t **list);

void selection_sort(int *array, size_t size);

int lomuto_partition(int *array, int low, int high, size_t size);
void _quick_sort_lomuto(int *array, int low, int high, size_t size);
void quick_sort_lomuto(int *array, size_t size);

int hoare_partition(int *array, int low, int high, size_t size);
void _quick_sort_hoare(int *array, int low, int high, size_t size);
void quick_sort_hoare(int *array, size_t size);

void shell_sort(int *array, size_t size);

void cocktail_sort(int *array, size_t size);

void counting_sort(int *array, size_t size);

void merge_sort(int *array, size_t size);
void m_sort(int *array, int begin, int end);
void merge(int *array, int begin, int mid, int end);

void heap_sort(int *array, size_t size);
void heapify(int *array, size_t size, int i, size_t total_size);

void count_sort_for_radix(int *array, int n, int placement_value);
void radix_sort(int *array, size_t size);

void _bitonic_sort(int *arr, int low, int cnt, int dir, int size);
void bitonic_sort(int *array, size_t size);
void bitonic_merge(int *arr, int low, int cnt, int dir, int size);

listint_t *create_doubly_listint(const int *array, size_t size);
#endif
