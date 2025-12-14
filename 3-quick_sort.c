#include <stddef.h>
#include "sort.h"

static void quick_sort_recursive(int *array, ssize_t low, ssize_t high,
		size_t size);
static ssize_t lomuto_partition(int *array, ssize_t low, ssize_t high,
		size_t size);
static void swap_ints(int *a, int *b);

/**
 * quick_sort - sorts an array of integers in ascending order using
 *              the Quick sort algorithm (Lomuto partition scheme)
 * @array: array of integers
 * @size: number of elements in @array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_recursive(array, 0, (ssize_t)size - 1, size);
}

/**
 * quick_sort_recursive - recursively sorts partitions of the array
 * @array: array of integers
 * @low: starting index of partition
 * @high: ending index of partition
 * @size: full array size (for print_array)
 */
static void quick_sort_recursive(int *array, ssize_t low, ssize_t high,
		size_t size)
{
	ssize_t p;

	if (low < high)
	{
		p = lomuto_partition(array, low, high, size);
		quick_sort_recursive(array, low, p - 1, size);
		quick_sort_recursive(array, p + 1, high, size);
	}
}

/**
 * lomuto_partition - partitions the array using Lomuto scheme
 * @array: array of integers
 * @low: starting index of partition
 * @high: ending index of partition (pivot position)
 * @size: full array size (for print_array)
 *
 * Return: final pivot index
 */
static ssize_t lomuto_partition(int *array, ssize_t low, ssize_t high,
		size_t size)
{
	int pivot = array[high];
	ssize_t i = low - 1;
	ssize_t j;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap_ints(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (i + 1 != high)
	{
		swap_ints(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * swap_ints - swaps two integers
 * @a: first integer
 * @b: second integer
 */
static void swap_ints(int *a, int *b)
{
	int tmp = *a;

	*a = *b;
	*b = tmp;
}
