#include "sort.h"

/**
 * heap_sort - sorts an array of integers in ascending order.
 * @array: Array of integers to sort.
 * @size: Array size.
 *
 * Return: Nothing.
 */

void heap_sort(int *array, size_t size)
{
	int top, tmp;

	if (!array || size < 1)
		return;

	for (tmp = size / 2 - 1; tmp >= 0; tmp--)
		pile(array, size, size, tmp);

	for (tmp = size - 1; tmp > 0; tmp--)
	{
		top = array[0];
		array[0] = array[tmp];
		array[tmp] = top;
		print_array(array, size);
		pile(array, tmp, size, 0);
	}
}

/**
 * pile - Find the largest number in a level.
 * @array: Array of integers.
 * @size_max: Maximum size in iteration.
 * @size: original array size
 * @position: root index
 */

void pile(int *array, size_t size_max, size_t size, size_t position)
{
	size_t aux, left, right, value;

	aux = position;
	left = 2 * position + 1;
	right = 2 * position + 2;

	if (left < size_max && array[left] > array[aux])
		aux = left;
	if (right < size_max && array[right] > array[aux])
		aux = right;
	if (aux != position)
	{
		value = array[position];
		array[position] = array[aux];
		array[aux] = value;
		print_array(array, size);
		pile(array, size_max, size, aux);
	}
}
