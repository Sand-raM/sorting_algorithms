#include "sort.h"

/**
 * swap_ints - swaps two intergers in an array
 * @a: first interger to be swaped
 * @b: second interger to be swaped
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - sorts an array of integers in ascending order
 * using the Selection sort algorithm
 * @array: array of the intergers
 * @size: size of the array
 *
 */
void selection_sort(int *array, size_t size)
{
	int *m;
	size_t x, r;

	if (array == NULL || size < 2)
		return;
	for (x = 0; x < size - 1; x++)
	{
		m = array + x;
		for (r = x + 1; r < size; r++)
			m = (array[r] < *m) ? (array + r) : m;
		if ((array + x) != m)
		{
			swap_ints(array + x, m);
			print_array(array, size);
		}
	}
}
