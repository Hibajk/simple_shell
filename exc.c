#include "shell.h"

/**
 * executeCommand - Executes a command
 * @cmd: the command to be executed
 * @argv: the name of the shell
 * @num: the counter
 * Return: The status of the execution
 */

int executeCommand(char **cmd, char **argv, int num)
{
	char *command;
	pid_t processID;
	int exitstatus;

	command = _getpath(cmd[0]);
	if (!command)
	{
		prerror(argv[0], cmd[0], num);
		F2darray(cmd);
		free(command), command = NULL;
		return (127);
	}
	processID = fork();
	if (processID == 0)
	{
		if (execve(command, cmd, environ) == -1)
		{
			free(command), command = NULL;
			F2darray(cmd);
		}
	}
	else
	{
		waitpid(processID, &exitstatus, 0);
		F2darray(cmd);
		free(command), command = NULL;
	}
	return(WEXITSTATUS(exitstatus));
}


