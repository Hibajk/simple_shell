#include "shell.h"

/**
 * printenv - prints environment variables
 * @command: command (not used in this function)
 * @status: exit status
 */

void printenv(char **command, int *status)
{
    int i = 0;

    while (environ[i])
    {
        write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
        write(STDOUT_FILENO, "\n", 1);
        i++;
    }

    freearr(command);
    *status = 0;
}
