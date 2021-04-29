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

    prime_l = get_prime(nums)

    if prime_l > 0:
        if prime_l % 2 == 0:
            return "Ben"
        else:
            return "Maria"
    return None


def get_prime(nums):
    """ Method that get all prime numbers.
        Args:
            nums: Is an array of n.
        Return: The total number of prime numbers.
    """

    prime_n = []

    for num in nums:
        if num == 1:
            prime_n.append(num)
        if num >= 2:
            flag = 0
            for iter in range(2, num):
                if num % iter == 0:
                    flag = 1
                    break
            if flag == 0:
                prime_n.append(num)
    set_prime = set(prime_n)
    return len(set_prime)
