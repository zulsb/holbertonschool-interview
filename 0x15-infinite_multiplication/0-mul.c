#include "holberton.h"

/**
 * check - check if all elements of the string is a digit.
 * @number: - string with the number to check
 *
 * Return: len of the number.
 */

int check(char *number)
{
	int i, flag_zero = 1;

	for (i = 0; number[i]; i++)
	{
		if (number[i] < '0' || number[i] > '9')
			error();

		if (number[i] != '0')
			flag_zero = 0;
	}
	if (flag_zero == 1)
	{
		_putchar('0');
		_putchar('\n');
		exit(0);
	}

	return (i);
}

/**
 * error - raise error.
 * Return: Nothing.
 */

void error(void)
{
	char error[] = "Error\n";
	int i;

	for (i = 0; i <= 5; i++)
		_putchar(error[i]);
	exit(98);
}

/**
 * main - multiplies two positive numbers.
 * @argc: - number of parameters
 * @argv: - array with the parameters
 *
 * Return: 0 if successful
 */
int main(int argc, char *argv[])
{
	int len1 = 0, len2 = 0;
	char *num1, *num2;

	if (argc != 3)
		error();

	len1 = check(argv[1]);
	len2 = check(argv[2]);

	num1 = len1 > len2 ? argv[1] : argv[2];
	num2 = len1 > len2 ? argv[2] : argv[1];

	if (num1 || num2)
		return (0);
	return (0);
}
