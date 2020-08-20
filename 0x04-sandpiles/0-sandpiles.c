#include "sandpiles.h"

/**
 * distribution - Sandpile distribution.
 * @grid1: Sandpile 1.
 * @grid2: Sandpile 2.
 *
 * Return: Nothing.
*/

void distribution(int grid1[3][3], int grid2[3][3])
{
	int row, column;

	for (row = 0; row < 3; row++)
	{
		for (column = 0; column < 3; column++)
		{
			if (grid1[row][column] > 3)
			{
				grid1[row][column] -= 4;
				if (column - 1 >= 0)
					grid2[row][column - 1]++;
				if (column + 1 < 3)
					grid2[row][column + 1]++;
				if (row - 1 >= 0)
					grid2[row - 1][column]++;
				if (row + 1 < 3)
					grid2[row + 1][column]++;
			}
		}
	}
}

/**
 * stable - Checks if a sandpile is stable or not.
 * @grid3: General sandpile.
 *
 * Return: 1 if the sandpile is stable or 0 if not.
*/

int stable(int grid3[3][3])
{
	int row, column;

	for (row = 0; row < 3; row++)
	{
		for (column = 0; column < 3; column++)
		{
			if (grid3[row][column] > 3)
				return (0);
		}
	}
	return (1);
}

/**
 * sandpiles_sum - Function that computes the sum of two sandpiles.
 * @grid1: Sandpile 1.
 * @grid2: Sandpile 2.
 *
 * Return: nothing.
*/

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int row, column;

	for (row = 0; row < 3; row++)
	{
		for (column = 0; column < 3; column++)
			grid1[row][column] = grid1[row][column] + grid2[row][column];
	}

	while (stable(grid1) == 0)
	{
		printf("=\n");
		for (row = 0; row < 3; row++)
		{
			for (column = 0; column < 3; column++)
			{
				if (column)
					printf(" ");
				printf("%i", grid1[row][column]);
			}
			printf("\n");
		}

		distribution(grid1, grid2);

		for (row = 0; row < 3; row++)
		{
			for (column = 0; column < 3; column++)
			{
				grid1[row][column] = grid1[row][column] + grid2[row][column];
				grid2[row][column] = 0;
			}
		}
	}
}
