#include "shell.h"

/**
 * get_path - retrieves the path of a command
 * @cmd: the command for which the path is retrieved
 * Return: NULL
 */

char *get_path(char *cmd)
{
	char *path;
	char *fcmd;
	char *cpath;
	struct stat st;
	int i = 0;

	while (cmd[i])
	{
		if (cmd[i] == '/')
		{
			if (stat(cmd, &st) == 0)
				return (_strdup(cmd));
			return (NULL);
		}
		i++;
	}
	path = 

