#include "shell.h"

/**
 * _prerror - prints an error message
 * @sn: the name of the string
 * @command: command
 * @number: the counter
 */

void _prerror(char *sn, char *command, int number)
{
	char *idx, messg[] = ": not found\n";
	idx = _itoa(number);

	write(STDERR_FILENO, sn, _strlen(sn));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, idx, _strlen(idx));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, command, _strlen(command));
	write(STDERR_FILENO, messg, _strlen(messg));

        free(idx);
        idx = NULL;
}	
