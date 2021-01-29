#!/usr/bin/python3
""" Recurse module """

import requests


def fillrecurse(response, word_list, dicti, after):
    """ Fill the dict increment count words.
    """
    ti = response.json().get("data").get("children")
    for t in ti:
        for hot_word in word_list:
            post = t.get("data").get("title")
            if post:
                word = post.split()
                for w in word:
                    if hot_word.lower() == w.lower():
                        dicti[hot_word] += 1
    if not after:
        for k, v in sorted(dicti.items(),
                           key=lambda items: items[1],
                           reverse=True):
            if v != 0:
                print("{}: {}".format(k, v))


def count_words(subreddit, word_list, after=None, dicti={}):
    """ Function that queries the Reddit API, parses the title of all
        hot articles, and prints a sorted count of given keywords.
    """
    headers = {'User-Agent': 'Python3'}
    params = {"limit": 100, 'after': after}
    response = requests.get("https://www.reddit.com/r/{}/hot/.json".
                            format(subreddit), headers=headers, params=params)

    try:
        if len(dicti) == 0:
            for hot_word in word_list:
                dicti[hot_word] = 0
        if response:
            arespon = response.json().get("data").get("after")
            if arespon:
                count_words(subreddit, word_list,
                            after=arespon, dicti=dicti)
                fillrecurse(response, word_list, dicti, after)
                return dicti
            else:
                fillrecurse(response, word_list, dicti, after)
                return dicti
    except Exception:
        return None
