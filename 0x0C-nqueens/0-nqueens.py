#!/usr/bin/python3
"""N queens problem"""
import sys


def queens_potitions(N, r, queens):
    """ The N queens puzzle is the challenge of placing
        N non-attacking queens on an N×N chessboard.

    """
    for i in range(N):
        flag = 0
        for j in queens:
            if abs(i - j[1]) == abs(r - j[0]):
                flag = 1
                break
            if i == j[1]:
                flag = 1
                break

        if flag == 0:
            queens.append([r, i])
            if r != N - 1:
                queens_potitions(N, r + 1, queens)
            else:
                print(queens)
            queens.pop()


if __name__ == "__main__":

    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        exit(1)

    if isinstance(sys.argv[1], int):
        print("N must be a number")
        exit(1)

    N = int(sys.argv[1])

    if N < 4:
        print("N must be at least 4")
        exit(1)

    r = 0
    queens = []
    queens_potitions(N, r, queens)
