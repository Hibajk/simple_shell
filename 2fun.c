#include "shell.h"

/**
 * pos_number - cheks if the input string represents a positive number
 * @strg: the string to be verified
 * Return: 1 if string is a positive number, 0 otherwise
 */

int pos_number(char *strg)
{
	int i;

	if (!strg)
		return (0);
	for (i = 0; strg[i]; i++)
	{

		if (strg[i] < '0' || strg[i] > '9')
			return (0);
	}
	return (1);
}

/**
 * atoi - converts a string to an integer
 * @strg: the input string to be converted
 * Return: the return value
 */

int atoi(char *strg)
{
	int i, number = 0;

	for (i = 0; strg[i]; i++)
	{
		number *= 10;
		number += (strg[i] - '0');
	}
	return (number);
}
