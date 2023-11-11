#include "shell.h"



/**
 * F2darray - simply frees a 2D array and sets pointers to NULL
 * @ar: the 2D array
 * Return: NULL
 */

void F2darray(char **array)
{
	if (!arr)
		return;

	for (int i = 0; arr[i]; ++i)
	{
		free(arr[i]);
		arr[i] = NULL;
	}

	free(arr);
	arr = NULL;
}
