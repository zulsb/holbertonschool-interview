#include "holberton.h"

/**
 * wildcmp - Function that compares two strings.
 * @s1: is a string to compare
 * @s2: is a string to compare.
 * Return: 1 if the strings can be considered identical otherwise return 0.
*/

int wildcmp(char *s1, char *s2)
{
	if (!*s1)
	{
		if (*s2 == '*')
			return (wildcmp(s1, s2 + 1));
		return (*s2 == '\0');
	}
	if (*s2 == '*')
		return (wildcmp(s1, s2 + 1) || wildcmp(s1 + 1, s2));
	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));
	return (0);
}
