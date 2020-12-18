#!/usr/bin/python3
""" Recurse module """


def count_words(subreddit, word_list):
    """ Method that queries the Reddit API and
        parses the title of all hot articles"""

    dic = {}

    for key, val in sorted(dic.items(), key=lambda x: x[1], reverse=True):
        if val != 0:
            print("{}: {}".format(key, val))
