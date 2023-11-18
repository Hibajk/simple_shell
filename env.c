#include "shell.h"

/**
 * printenv - prints environment variables
 * @cmd: command (not used in this function)
 * @sts: exit status
 */

void printenv(char **cmd, int *sts)
{
	int i = 0;

	while (environ[i])
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	free2DArray(cmd);
	*sts = 0;
}
