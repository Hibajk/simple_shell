#include "shell.h"

/**
 * exitShell - function to exit the shell
 * @cmd: the command
 * @sts: exit status
 * @argv: the arguments
 * @index: idx of command
 */

void exitShell(char **cmd, char **argv, int *sts, int index)
{
	int exit_value = (*sts);
	char *idx, mssg[] = ": exit: illegal number: ";
	char idx_str[20];

	if (cmd[1])
	{
		if (pos_num(cmd[1]))
		{
			exit_value = _atoi(cmd[1]);
		}
		else
		{
			snprintf(idx_str, sizeof(idx_str), "%d", index);
		index = _itoa(index);
		write(STDERR_FILENO, argv[0], _strlen(argv[0]));
	        write(STDERR_FILENO, ": ", 2);
	        write(STDERR_FILENO, idx, _strlen(idx));
	        write(STDERR_FILENO, mssg, _strlen(mssg));
	        write(STDERR_FILENO, cmd[1], _strlen(cmd[1]));
	        write(STDERR_FILENO, "\n", 1);
	        free(idx);
	        free(cmd);
	        F2darray(cmd);
	       (*sts) = 2;
	       return;
		}
	}
	free(cmd);
	F2darray(cmd);
	exit(exit_value);
}
