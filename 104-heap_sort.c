#include "sort.h"

void swap_ints(int *a, int *b);
void max_heapify(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

/**
 * swap_ints - Swap two integers in an array
 * @a: first integer
 * @b: second integer
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * max_heapify - Turn a binary tree into a complete binary heap
 * @array: array of integers representing a binary tree
 * @size: size of the array/tree
 * @base: index of the base row of the tree
 * @root: root node of the binary tree
 */
void max_heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t l, rt, lg;

	l = 2 * root + 1;
	rt = 2 * root + 2;
	lg = root;

	if (l < base && array[l] > array[lg])
		lg = l;
	if (rt < base && array[rt] > array[lg])
		lg = rt;

	if (lg != root)
	{
		swap_ints(array + root, array + lg);
		print_array(array, size);
		max_heapify(array, size, base, lg);
	}
}

/**
 * heap_sort - Sort an array of integers in ascending
 *             order using the heap sort algorithm
 * @array: array of integers
 * @size: size of the array
 */
void heap_sort(int *array, size_t size)
{
	int c;

	if (array == NULL || size < 2)
		return;

	for (c = (size / 2) - 1; c >= 0; c--)
		max_heapify(array, size, size, c);

	for (c = size - 1; c > 0; c--)
	{
		swap_ints(array, array + c);
		print_array(array, size);
		max_heapify(array, size, c, 0);
	}
}
