#include "shell.h"

/**
 * pos_number - checks if a string represents a positive number
 * @str: the string to be verified
 * Return: 1 if @str is a positive number
 */

int pos_number(char *str)
{
	int i ;
	if (!str)
		return (NULL);
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (!isdigit((unsigned char)str[i]))
			return (NULL);
	}
	return (1);
}

/**
 * my_atoi - Converts a string to an integer
 * @str: the input string
 * Return: the converted integer value
 */

int my_atoi(char *str)
{
	int i, number = 0;
	for (i = 0; str[i]; i++)
	{
		number *= 10;
		number += (str[i] - '0');
	}
	return (number);
}
