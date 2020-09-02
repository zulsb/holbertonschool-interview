#!/usr/bin/python3
"""Module that reads stdin line by line and print metrics"""
from sys import stdin

stat = {"200": 0, "301": 0, "400": 0, "401": 0,
        "403": 0, "404": 0, "405": 0, "500": 0}
ctr = 0
total_size = 0


def prints():
    """Print metrics"""
    print("File size: ", total_size)
    for key in sorted(stat.keys()):
        if stat[key]:
            print("{}: {:d}".format(key, stat[key]))

try:
    for line in stdin:
        status_code = line.split('"')[2].split(" ")[1]
        size = int(line.split('"')[2].split(" ")[2])
        total_size += size
        ctr += 1

        for key in sorted(stat.keys()):
            if status_code == key:
                stat[key] += 1
        if ctr == 10:
            ctr = 0
            prints()

except KeyboardInterrupt:
    prints()
    raise
prints()