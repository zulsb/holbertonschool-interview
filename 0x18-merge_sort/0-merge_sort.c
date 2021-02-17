#include "sort.h"

/**
 * merge_subarray - Merges two subarrays of integer.
 * @array: Pointer to array of integers.
 * @ri: Right subarry.
 * @le: Left subarry.
 * @size: Size of array.
 *
 * Return: Nothing.
 */

void merge_subarray(int *array, int *ri, int *le, size_t size)
{
	int i = 0, j = 0, s = 0;
	int l_cont = size / 2, r_cont = size - l_cont;

	while (i < l_cont && j < r_cont)
	{
		if (le[i] <= ri[j])
		{
			array[s] = le[i];
			i++;
		}
		else
		{
			array[s] = ri[j];
			j++;
		}
		s++;
	}
	while (i < l_cont)
	{
		array[s] = le[i];
		i++;
		s++;
	}
	while (j < r_cont)
	{
		array[s] = ri[j];
		j++;
		s++;
	}

	printf("Merging...\n");
	printf("[left]: ");
	print_array(le, l_cont);
	printf("[right]: ");
	print_array(ri, r_cont);
	printf("[Done]: ");
	print_array(array, size);
}

/**
 * merge_sort - Sorts an array of integers in ascending order.
 * @array: Pointer to array of integer.
 * @size: Size of array.
 *
 * Return: Nothing.
 */

void merge_sort(int *array, size_t size)
{
	int ri[300], le[300];
	size_t middle = size / 2, pos;

	if (size < 2 || array == NULL)
		return;
	for (pos = 0; pos < middle; pos++)
		le[pos] = array[pos];
	for (pos = middle; pos < size; pos++)
		ri[pos - middle] = array[pos];
	merge_sort(le, middle);
	merge_sort(ri, size - middle);
	merge_subarray(array, ri, le, size);
}
