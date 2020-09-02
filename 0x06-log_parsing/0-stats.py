#!/usr/bin/python3
"""Module that reads stdin line by line and print metrics"""
import sys

stat = {"200": 0, "301": 0, "400": 0, "401": 0,
        "403": 0, "404": 0, "405": 0, "500": 0}
ctr = 0
total_size = 0

if __name__ == "__main__":
    try:
        for line in sys.stdin:
            status_code = line.split('"')[2].split(" ")[1]
            size = int(line.split('"')[2].split(" ")[2])
            total_size += size
            ctr += 1

            for key in sorted(stat.keys()):
                if status_code == key:
                    stat[key] += 1
            if ctr == 10:
                print("File size: {:d}".format(total_size))
                for key in sorted(stat.keys()):
                    if stat[key]:
                        print("{}: {:d}".format(key, stat[key]))
                ctr = 0

    except KeyboardInterrupt:
        print("File size: {:d}".format(total_size))
        for key in sorted(stat.keys()):
            if stat[key]:
                print("{}: {:d}".format(key, stat[key]))
        raise
    print("File size: {:d}".format(total_size))
    for key in sorted(stat.keys()):
        if stat[key]:
            print("{}: {:d}".format(key, stat[key]))
