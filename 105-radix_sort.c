#include "sort.h"

/**
 * radix_sort - sorts an array of integers in ascending order
 * using the Radix sort algorithm
 * @array: array of the interger
 * @size: size of the array
 */
void radix_sort(int *array, size_t size)
{
	int g = 1, x = 10;
	size_t i, f;

	if (!array || size == 1)
		return;
	while (g)
	{
		g = 0;
		for (i = 1, f = 1; i <  size; i++, f++)
		{
			if ((array[i - 1] % (x * 10)) / ((x * 10) / 10) > 0)
				g = 1;
			if (((array[i - 1] % ) / (x / 10)) > ((array[i] % x) / (x / 10)))
			{
				array[i - 1] = array[i - 1] + array[i];
				array[i] = array[i - 1] - array[i];
				array[i - 1] = array[i - 1] - array[i];
				if ((i - 1) > 0)
					i = i - 2;
			}
		}
		print_array(array, size);
		x = x * 10;
	}
}
