#include <stdlib.h>
#include "shell.h"
#include <string.h>
#include <stdio.h>

/**
 * main - the main functions
 * @acc: arg count
 * @argv: arguments
 * Return: 0
 */

int main(int acc, char **argv)
{
	int sts = 0, number = 0;
	char *inputString = NULL;
	char **cmd = NULL;
	(void) acc;

	while (1)
	{
		inputString = pro_shell();
		if (inputString == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			free(inputString), inputString = NULL;
			return (sts);
		}
		number++;

		cmd = cmd_tok(inputString);
		if (!cmd)
			continue;

		if (_strcmp(cmd[0], "exit") == 0)
			exit(sts);
		if (_strcmp(cmd[0], "env") == 0)
			printenv(cmd, &sts);
		else
			sts = _execution(cmd, argv, number);
	}
}
