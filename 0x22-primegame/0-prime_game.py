#!/usr/bin/python3

""" Prime Game """


def isWinner(x, nums):
    """ Game module.
        Args:
            x: Is the number of rounds.
            nums: Is an array of n.
        Return: Name of the player that won the most rounds.
            If the winner cannot be determined, return None.
    """

    s = {"Maria": 0, "Ben": 0}
    primes = [0, 0, 2]
    add_prime(max(nums), primes)

    for round in range(x):
        _sum = sum((i != 0 and i <= nums[round])
                   for i in primes[:nums[round] + 1])
        if (_sum % 2):
            winner = "Maria"
        else:
            winner = "Ben"
        if winner:
            s[winner] += 1

    if s["Maria"] > s["Ben"]:
        return "Maria"
    elif s["Ben"] > s["Maria"]:
        return "Ben"

    return None


def add_prime(n, primes):
    """ Method that all primes.
    """

    last_prime = primes[-1]
    if n > last_prime:
        for i in range(last_prime + 1, n + 1):
            if is_prime(i):
                primes.append(i)
            else:
                primes.append(0)


def is_prime(n):
    """ Method taht check if n is a prime number.
    """
    for i in range(2, int(n ** 0.5) + 1):
        if not n % i:
            return False
    return True
