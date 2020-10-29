#!/usr/bin/python3
"""N queens problem"""
import sys


def queens_potitions(N, row, queens):
    """ The N queens puzzle is the challenge of placing
        N non-attacking queens on an N×N chessboard.

    """
    for i in range(N):
        flag = 0
        for j in queens:
            if abs(i - j[1]) == abs(row - j[0]):
                flag = 1
                break
            if i == j[1]:
                flag = 1
                break

        if flag == 0:
            queens.append([row, i])
            if row != N - 1:
                queens_potitions(N, row + 1, queens)
            else:
                print(queens)
            queens.pop()


if __name__ == "__main__":

    N = int(sys.argv[1])
    row = 0
    queens = []
    queens_potitions(N, row, queens)
