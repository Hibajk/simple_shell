#include "shell.h"

/**
 * free2DArray - Frees a 2D array
 * @array: The 2D array to be freed
 * Return: None
 */
void free2DArray(char **array)
{
	int i = 0;

	if (!array)
		return;

	while (array[i])
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}

	free(array);
	array = NULL;
}
