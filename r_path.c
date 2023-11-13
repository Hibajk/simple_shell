#include "shell.h"

/**
 * _genv - gets an environment variable
 * @path: the name of the environment variable
 * Return: NULL if not found
 */

char *_genv(char *path)
{
	char *temp;
	char *keyy;
	char *vlue;
	char *envv;
	int i = 0;

	while (env[i])
	{
		temp = _strdup(env[i]);
		keyy = strtok(temp, "=");
		if (_strcmp(keyy, path) == 0)
		{
			vlue = strtok(NULL, "\n");
			envv = _strdup(vlue);
			free(temp);
			return (envv);
		}
		free(temp), temp = NULL;
		i++;
	}
	return (NULL);
}
