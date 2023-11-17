#include "shell.h"

/**
 * _execution - function that executes a command
 * @cmd: command to execute
 * @argv: name of the shell
 * @number: the counter
 * Return: return the status
 */

int _execution(char **cmd, char **argv, int number)
{
	char *fcommand;
	pid_t child;
	int status;

	fcommand = _getpath(cmd[0]);
	if (!fcommand)
	{
		prerror(argv[0], cmd[0], number);
		free2DArray(cmd);
		free(fcommand), fcommand = NULL;
		return (127);
	}
	child = fork();
	if (child == 0)
	{
		if (execve(fcommand, cmd, environ) == -1)
		{
			free(fcommand), fcommand = NULL;
			free2DArray(cmd);
		}
	}
	else
	{
		waitpid(child, &status, 0);
		free2DArray(cmd);
		free(fcommand), fcommand = NULL;
	}
	return (WEXITSTATUS(status));
}
