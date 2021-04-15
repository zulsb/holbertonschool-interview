#include "regex.h"

/**
* regex_match - Checks whether a given pattern matches a given string.
* @str: Is the string to scan.
* @pattern: Is the regular expression.
*
* Return: 1 if the pattern matches the string or 0 if it doesn’t.
*/

int regex_match(char const *str, char const *pattern)
{
	int dot = 0, a = 0;

	if (!str || !pattern)
		return (0);

	dot = *str && (*str == *pattern || *pattern == '.');
	a = *(pattern + 1) == '*';

	if (!*str && !a)
		return (*pattern ? 0 : 1);
	else if (dot && a)
		return (regex_match(str + 1, pattern) || regex_match(str, pattern + 2));
	else if (dot && !a)
		return (regex_match(str + 1, pattern + 1));
	else if (a)
		return (regex_match(str, pattern + 2));
	return (0);
}
