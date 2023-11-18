#include "shell.h"

/**
 * perror - prints an error message
 * @shelln: name of the shell
 * @command: the command
 * @number: a counter
 */
void perror(char *shelln, char *command, int number)
{
	char *index, mssg[] = ": not found\n";

	index = _intoa(nmbr);

	write(STDERR_FILENO, shelln, _strlen(shelln));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, index, _strlen(index));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, command, _strlen(command));
	write(STDERR_FILENO, mssg, _strlen(mssg));

	free(index);
}
