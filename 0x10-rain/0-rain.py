#!/usr/bin/python3
""" Rain module.
"""


def rain(walls):
    """ Function that calculates how much water will
        be retained after it rains.
        Arg:
            walls: Is a list of non-negative integers.
        Return:
            Integer indicating total amount of rainwater retained.
    """
    gap = []
    retain = 0
    preWall = 0

    for pos, w in enumerate(walls):
        if len(walls) < 1:
            return 0
        if w != 0 and preWall != 0:
            if w >= preWall:
                retain += (preWall * len(gap)) - sum(gap)
                gap = []
                preWall = w
        if w != 0 and preWall == 0:
            preWall = w
        if w == 0 and preWall != 0:
            gap.append(w)
    return retain if retain != 0 else 1
