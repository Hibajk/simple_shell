#include "shell.h"

/**
 * freearr - frees a 2D array of strings
 * @arr: the 2D array to be freed
 * Return: none
 */

void freearr(char **arr)
{
    if (!arr)
        return;

    for (int i = 0; arr[i]; i++)
    {
        free(arr[i]);
        arr[i] = NULL;
    }

    free(arr), arr = NULL;
}
