#!/usr/bin/python3
"""
    This module contains the canUnlockAll function.
"""


def canUnlockAll(boxes):
    """Method that determines if all the boxes can be opened
        Arg:
            boxes: Is a list of lists.
    """
    # li = []
    # for i in range(len(boxes)):
    #     for o in boxes[i]:
    #         li.append(boxes[0])
    # print(li, end=" ")

    box = len(boxes) * [False]
    box[0] = True
    key = [0]

    for e in range(len(boxes)):
        for i in boxes[e]:
            if not box[i]:
                if boxes[e] is not boxes[i]:
                    box[i] = True
                    key.append(i)
    return all(box)
