#include "sort.h"

/**
 * swap_ints - swaps two intergers in an array
 * @a: first interger
 * @b: second interger
 */
void swap_ints(int *a, int *b)
{
	int ptr;

	ptr = *a;
	*a = *b;
	*b = ptr;
}

/**
 * shell_sort - sorts an array of integers in ascending order
 *  using the Shell sort algorithm, using the Knuth sequence
 *  @array: array of intergers
 *  @size: size of the array
 *
 */
void shell_sort(int *array, size_t size)
{
	size_t h, x, r;

	if (array == NULL || size < 2)
		return;
	for (h = 1; h < (size / 3);)
		h = h * 3 + 1;
	for (; h >= 1; h /= 3)
	{
		for (x = h; x < size; x++)
		{
			r = x;
			while (r >= h && array[r - h] > array[r])
			{
				swap_ints(array + r, array + (r - h));
				r -= h;
			}
		}
		print_array(array, size);
	}
}
