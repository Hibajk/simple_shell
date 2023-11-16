#include "shell.h"

/**
 * _intoa - converts an integer to ASCII
 * @n: the integer
 * Return: a dynamically allocated string containing the ASCII represe
 */

char *_intoa(int n)
{
    char buffer[20];
    int i = 0;

    if (n == 0)
    {
        buffer[i++] = '0';
    }
    else
    {
        while (n > 0)
        {
            buffer[i++] = (n % 10) + '0';
            n /= 10;
        }
    }

    buffer[i] = '\0';
    reverse_string(buffer, i);
    return _strdup(buffer);
}

/**
 * reverse_str -  function that reverses a string in place
 * @str: the string
 * @len: length of the string
 */

void reverse_str(char *str, int len)
{
    int i = 0, nd = len - 1;

    while (i < nd)
    {
        char tmp = str[i];
        str[i] = str[nd];
        str[nd] = tmp;
        i++;
        nd--;
    }
}
