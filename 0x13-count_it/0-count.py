#!/usr/bin/python3
""" Recurse module """

from requests import get

API = "https://www.reddit.com/"
headers = {'user-agent': 'zulsb'}


def count_words(subreddit, word_list, after="", word_dic={}):
    """ Function queries the Reddit API, parses the title of all
        hot articles, and prints a sorted count of given keywords.
    """
    if not word_dic:
        for w in word_list:
            word_dic[w] = 0

    if after is None:
        word_list = [[key, value] for key, value in word_dic.items()]
        word_list = sorted(word_list, key=lambda x: (-x[1], x[0]))
        for w in word_list:
            if w[1]:
                print("{}: {}".format(w[0].lower(), w[1]))
        return None

    url = API + "r/{}/hot/.json".format(subreddit)
    params = {'limit': 100, 'after': after}
    r = get(url, headers=headers, params=params, allow_redirects=False)

    if r.status_code != 200:
        return None
    try:
        js = r.json()
    except Exception:
        return None

    try:
        data = js.get("data")
        after = data.get("after")
        children = data.get("children")
        for c in children:
            datapost = c.get("data")
            title = datapost.get("title")
            lower = [s.lower() for s in title.split(' ')]
            for w in word_list:
                word_dic[w] += lower.count(w.lower())
    except Exception:
        return None
    count_words(subreddit, word_list, after, word_dic)
