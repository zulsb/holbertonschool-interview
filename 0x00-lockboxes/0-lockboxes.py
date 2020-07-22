#!/usr/bin/python3
"""
    This module contains the canUnlockAll function.
"""


def canUnlockAll(boxes):
    """Method that determines if all the boxes can be opened
        Arg:
            boxes: Is a list of lists.
    """
    box = len(boxes) * [False]
    box[0] = True
    keys = [0]

    if keys:
        for each in range(len(boxes)):
            for i in boxes[each]:
                if boxes[each] is not boxes[i]:
                    box[i] = True
                if i not in keys and i < len(boxes):
                    keys.append(i)
        return all(box)
