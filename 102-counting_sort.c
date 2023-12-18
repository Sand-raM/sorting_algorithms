#include "sort.h"

/**
 * counting_sort -  sorts an array of integers in ascending order
 * using the Counting sort algorithm
 * @array: pointer to the array
 * @size: size of the array
 *
 */
void counting_sort(int *array, size_t size)
{
	int max, j, *count, *aux;
	size_t i;

	if (!array || size < 2)
		return;
	max = array[0];
	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	count = calloc((max + 1), sizeof(int));
	for (i = 0; i < size; i++)
	{
		count[array[i]]++;
	}
	for (j = 1; j < max; j++)
	{
		count[j + 1] += count[j];
	}
	print_array(count, max + 1);
	aux = malloc(sizeof(int) * size);
	for (i = 0; i < size; i++)
	{
		count[array[i]]--;
		aux[count[array[i]]] = array[i];
	}
	for (i = 0; i < size; i++)
	{
		array[i] = aux[i];
	}
	free(aux);
	free(count);
}
