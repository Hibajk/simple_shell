#include "shell.h"

/**
 * pro_shell - reads a line from the user and prints a prompt
 *
 * Return: the line read from the user, or NULL on failure
 */

char *pro_shell(void)
{
	char *inputString = NULL;
	size_t ln = 0;
	ssize_t read_chars;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);

	read_chars = getline(&inputString, &ln, stdin);

	if (read_chars == -1)
	{
		free(inputString);
		return (NULL);
	}
	return (inputString);
}
