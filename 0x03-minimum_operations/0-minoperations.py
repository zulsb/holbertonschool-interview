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
    if n:
        while n > 1:
            if n % 2 == 0:
                n = n / 1
            else:
                n += 1
                count += 2
            count += 1
        return count
    return 0
