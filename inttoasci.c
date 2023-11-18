#include "shell.h"

/**
 * _intoa - converts an integer to ASCII
 * @n: the integer
 * Return: a dynamically allocated string containing the ASCII represe
 */

char *_intoa(int n)
{
	char buff[20];
	int i = 0;

	if (n == 0)
		buff[i++] = '0';
	else
	{
		while (n > 0)
		{
			buff[i++] = (n % 10) + '0';
			n /= 10;
		}
	}
	buff[i] = '\0';
	reverse_string(buff, i);
	return (_strdup(buff));
}

/**
 * reverse_str -  function that reverses a string in place
 * @string: the string
 * @ln: length of the string
 */

void reverse_str(char *string, int ln)
{
	char temp;
	int i = 0, nd = ln - 1;

	while (i < nd)
	{
		temp = string[i];
		string[i] = string[nd];
		string[nd] = temp;
		i++;
		nd--;
	}


}
