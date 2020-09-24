#!/usr/bin/python3
"""
Contains the method that determines represents a valid UTF-8 encoding.
"""


def validUTF8(data):
    """ Method that determines if a given data set represents a valid
        UTF-8 encoding.
        Args:
        data: Represented by a list of integers.
    """

    validation = 0
    for i in data:
        i = format(i, "#010b")[-8:]
        if validation != 0:
            validation -= 1
            if not i.startswith("10"):
                return False
        elif i[0] == "1":
            if validation == 1 or validation > 4:
                return False
            validation -= 1

    return True if validation == 0 else False
