#include "slide_line.h"

/**
 * slide_line - Slides and merges an array of integers.
 * @line: Points to an array of integers containing size elements.
 * @size: Number of elements.
 * @direction: Merged direction.
 *
 * Return: return 1 upon success, or 0 upon failure.
 */

int slide_line(int *line, size_t size, int direction)
{
	int size_aux = size;

	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
		return (0);

	switch (direction)
	{
		case SLIDE_LEFT:
			left(line, size_aux);
			break;
		case SLIDE_RIGHT:
			right(line, size_aux);
			break;
	}

	return (1);
}

/**
 * left - Slides and merges an array of integers to left.
 * @line: Points to an array of integers containing size elements.
 * @size_aux: Number of elements.
 *
 * Return: Nothing.
*/

void left(int *line, int size_aux)
{
	int i, j = 0, aux = line[0];

	for (i = 0; i < size_aux; i++)
	{
		if (line[i])
		{
			if (i != 0)
			{
				if (line[i] == aux)
				{
					line[j] = line[i] + aux;
					aux = 0;
					j++;
				}
				else
				{
					if (aux != 0)
					{
						line[j] = aux;
						j++;
					}
					if (i == size_aux - 1)
					{
						line[j] = line[i];
						j++;
					}
					aux = line[i];
				}
			}
		}
	}
}

/**
 * right - Slides and merges an array of integers to right.
 * @line: Points to an array of integers containing size elements.
 * @size_aux: Number of elements.
 *
 * Return: Nothing.
 */

void right(int *line, int size_aux)
{
	int i, j = size_aux - 1, aux = line[j];

	for (i = size_aux - 1 ; i >= 0; i--)
	{
		if (line[i])
		{
			if (i != size_aux - 1)
			{
				if (line[i] == aux)
				{
					line[j] = line[i] + aux;
					aux = 0;
					j--;
				} else
				{
					if (aux != 0)
					{
						line[j] = aux;
						j--;
					}
					if (i == 0)
					{
						line[j] = line[i];
						j--;
					}
					aux = line[i];
				}
			}
		}
	}
}
