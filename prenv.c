#include "shell.h"

/**
 * prv - prints the environment information
 * @cmd: the command related with the environment
 * @sts: exit status
 */

void prv(char **cmd, int *sts)
{
	int i = 0;
	while (env[i])
	{
		write(STDOUT_FILENO, env[i], _strlen(env[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	F2darray(cmd);
	*sts = 0;
}
