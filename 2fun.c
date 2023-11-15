#include "shell.h"

/**
 * positive_num - checks if all characters in the string are digits
 * @str: string to verify
 * Return: 1 if str consists of only digits, otherwise 0
 */

int positive_num(char *str)
{
    if (!str)
        return 0;

    for (int i = 0; str[i]; i++)
    {
        if (str[i] < '0' || str[i] > '9')
            return 0;
    }

    return 1;
}

/**
 * _atoi - convert string to integer
 * @str: string
 * Return: converted integer value
 */

int _atoi(char *str)
{
    int i, num = 0;

    for (int i = 0; str[i]; i++)
    {
        num *= 10;
        num += (str[i] - '0');
    }

    return num;
}
