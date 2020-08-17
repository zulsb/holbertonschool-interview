#include "sandpiles.h"

/**
 * sandpiles_sum - Function that computes the sum of two sandpiles.
 * @grid1: Sandpile 1 int type.
 * @grid2: Sandpile 2 int type.
 *
 * Return: nothing.
*/

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int row = 0, column = 0;


	for (row = 0; row < 3; row++)
	{
		for (column = 0; column < 3; column++)
		{
			grid1[row][column] = grid1[row][column] + grid2[row][column];
		}
	}
}
