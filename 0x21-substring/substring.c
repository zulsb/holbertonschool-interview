#include "substring.h"

/**
 * find_substring -  Finds all the possible substrings containing a list.
 * @s: Is the string to scan.
 * @words: Is the array of words all substrings must be a concatenation.
 * @nb_words: Is the number of elements in the array words.
 * @n: Holds the address at which to store the number of elements in the
 * returned array.
 *
 * Return: An allocated array, storing each index in s, at which a
 * substring was found. If no solution is found return NULL.
 */

int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int indexx, count, string_l, w_len, checks, i, j, k;
	int *match, *i_arra;

	if (!s || !words || !n || nb_words == 0)
		return (NULL);

	string_l = strlen(s);
	w_len = strlen(words[0]);
	i_arra = malloc(string_l * sizeof(int));
	if (!i_arra)
		return (NULL);
	match = malloc(nb_words * sizeof(int));
	if (!match)
		return (NULL);

	for (i = count = 0; i <= string_l - nb_words * w_len; i++)
	{
		memset(match, 0, nb_words * sizeof(int));
		for (j = 0; j < nb_words; j++)
		{
			for (k = 0; k < nb_words; k++)
			{
				indexx = i + j * w_len;
				checks = strncmp(s + indexx, *(words + k), w_len);
				if (!*(match + k) && !checks)
				{
					*(match + k) = 1;
					break;
				}
			}
			if (k == nb_words)
				break;
		}
		if (j == nb_words)
			*(i_arra + count) = i, count += 1;
	}
	free(match);
	*n = count;
	return (i_arra);
}
