#!/usr/bin/python3
""" Module that rotate 2D matrix.
"""


def rotate_2d_matrix(matrix):
    """Method that rotate it 90 degrees clockwise.
        Arg:
            matrix: Have 2 dimensions.
        Return:
            Anything.
    """

    c = matrix.copy()

    for iter in range(len(matrix[0])):
        aux = []
        for row in reversed(c):
            aux.append(row[iter])
        matrix[iter] = aux
