#!/usr/bin/python3

"""
    Contains the method that calculates minimum operations.
"""


def minOperations(n):
    """ Method that calculates the fewest number of operations
        needed to result in exactly n H characters in the file.
        Args:
            n: Is a number to print H characters.
    """
    count = 0
    seg_ment = 2

    if n:
        while n != 1:
            if n % seg_ment == 0:
                n = n // seg_ment
                count += seg_ment
            else:
                seg_ment += 1
        return count
    return 0
