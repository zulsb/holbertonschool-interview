#!/usr/bin/python3

""" Island perimeter module """


def island_perimeter(grid):
    """ Method that returns the perimeter of the island described in grid.
        Arg:
            grid: Is a list of list of integers.
        Return:
            Perimeter.
    """

    lenGrid = len(grid[0])
    water = [0] * (lenGrid + 2)
    p = 0

    grid.insert(0, water)
    grid.append(water)

    for row in range(1, len(grid) - 1):
        grid[row].insert(0, 0)
        grid[row].append(0)
        for col in range(1, lenGrid + 1):
            if grid[row][col] == 1:
                if grid[row - 1][col] == 0:
                    p += 1
                if grid[row + 1][col - 1] == 0:
                    p += 1
                if grid[row][col - 1] == 0:
                    p += 1
                if grid[row][col + 1] == 0:
                    p += 1
    return p
