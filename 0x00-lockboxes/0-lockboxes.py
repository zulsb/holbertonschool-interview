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

    op_en = [False] * len(boxes)
    op_en[0] = True
    key = [0]

    while key:
        lis = key.pop()
        for i in boxes[lis]:
            if not op_en[i]:
                op_en[i] = True
                key.append(i)
    return all(op_en)
