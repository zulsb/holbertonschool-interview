#include "palindrome.h"

/**
 * is_palindrome - Checks whether or not a given
 * unsigned integer is a palindrome.
 * @n: Number to be checked.
 *
 * Return: 1 if n is a palindrome, and 0 otherwise.
 */

int is_palindrome(unsigned long n)
{
	unsigned long number = 0, aux = n;

	while (aux != 0)
	{
		number = number * 10;
		number = number + (aux % 10);
		aux = aux / 10;
	}

	if (number == n)
		return (1);
	return (0);
}
