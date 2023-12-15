#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - Order a subset of an array of integers according to
 *                    the lomuto partition scheme (last element as pivot).
 * @array: The array of integers.
 * @size: The size of the array.
 * @left: The starting index of the subset to order.
 * @right: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *vt, b, w;

	vt = array + right;
	for (b = w = left; w < right; w++)
	{
		if (array[w] < *vt)
		{
			if (b < w)
			{
				swap_ints(array + w, array + b);
				print_array(array, size);
			}
			b++;
		}
	}

	if (array[b] > *vt)
	{
		swap_ints(array + b, vt);
		print_array(array, size);
	}

	return (b);
}

/**
 * lomuto_sort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @left: The starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 *
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int pt;

	if (right - left > 0)
	{
		pt = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, pt - 1);
		lomuto_sort(array, size, pt + 1, right);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending
 *              order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
