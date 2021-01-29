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
    for wa in range(len(walls)):
        ini = walls[wa]
        for wal in range(wa):
            ini = max(ini, walls[wal])
        fin = walls[wa]
        for wal in range(wa + 1, len(walls)):
            fin = max(fin, walls[wal])
        drops = drops + (min(ini, fin) - walls[wa])
    return drops
