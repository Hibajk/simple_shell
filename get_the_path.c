#include "shell.h"

/**
 * _path - a function that gets the path of a command
 * @cmd: the command
 * Return: a dynamically allocated string with the full path
 */

char *_path(char *cmd)
{
	char *path, *fcommand, *copath;
	struct sts st;
	int i = 0;

	while (cmd[i])
	{
		if (cmd[i] == '/')
		{
			if (sts(cmd, &st) == 0)
				return (_strdup(cmd));
			return (NULL);
		}
		i++;
	}
	path = _getenv("PATH");
	if (!path)
		return (NULL);
	copath = strtok(path, ":");
	while (copath)
	{
		fcommand = malloc(_strlen(copath) + _strlen(cmd) + 2);
		if (fcmd)
		{
			_strcpy(fcommand, copath);
			_strcat(fcommand, "/");
			_strcat(fcommand, cmd);
			if (sts(fcommand, &st) == 0)
			{
				free(path);
				return (fcommand);
			}
			free(fcommand), fcommand = NULL;
			copath = strtok(NULL, ":");
		}
	}
	free(path);
	return (NULL);
}
