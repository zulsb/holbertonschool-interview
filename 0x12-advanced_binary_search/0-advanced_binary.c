#include "search_algos.h"

/**
 * advanced_binary - Search for a value in a sorted array of integers.
 * @array: Pointer to the first element of the array to search in.
 * @size: Number of elements in array.
 * @value: Value to search for.
 *
 * Return: Index where value is located or -1.
 */

int advanced_binary(int *array, size_t size, int value)
{
	if (!array || size < 1)
		return (-1);
	return (search_binary(array, 0, size, value));
}

/**
 * search_binary - Function to search in array.
 * @array: Pointer to the first element of the array to search in.
 * @start_idx: Start index to find array.
 * @end_idx: End index to find array.
 * @value: Number to search in array.
 *
 * Return: Index where value is located or -1.
 */

int search_binary(int *array, size_t start_idx, size_t end_idx, int value)
{
	size_t i, position;

	if (start_idx == end_idx)
		return (-1);

	printf("Searching in array: ");
	for (i = start_idx; i < end_idx; i++)
	{
		printf("%d", array[i]);
		if (i < end_idx - 1)
			printf(", ");
	}
	printf("\n");

	position = (start_idx + end_idx - 1) / 2;

	if (array[position] == value)
	{
		if (array[position - 1] < value)
			return (position);
		return (search_binary(array, start_idx, position + 1, value));
	}
	if (array[position] < value)
		return (search_binary(array, position + 1, end_idx, value));
	else if (array[position] > value)
		return (search_binary(array, start_idx, position + 1, value));
	return (-1);
}
