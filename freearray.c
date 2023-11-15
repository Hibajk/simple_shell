#include "shell.h"

/**
 * free_2d_array - frees a 2D array of strings
 * @arr: the 2D array to be freed
 * Return: none
 */

void free_2d_array(char **arr)
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
