#include "shell.h"

/**
 * *pr_shell - reads and prints a line
 *
 * Return: line
 */

char *pr_shell(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read_count;

	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "& ", 2);
	}

	read_count = getline(&line, &len, stdin);

	if (read_count == -1)
	{
		free(line);
		line = NULL;
		return NULL;
	}
	
	return line;
}
