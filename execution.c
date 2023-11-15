#include "shell.h"

/**
 * _exec - function that executes a command
 * @command: command to execute
 * @argv: name of the shell
 * @nmbr: a counter
 * Return: return the status
 */

int _exec(char **command, char **argv, int nmbr)
{
    char *fcmd;
    pid_t child;
    int status;

    fcmd = _getpath(command[0]);
    if (!fcmd)
    {
        prerror(argv[0], command[0], nmbr);
        free(fcmd);
        Fr2Darray(command);
        return 127;
    }

    child = fork();
    if (child == -1)
    {
        perror("fork");
        free(fcmd);
        Fr2Darray(command);
        return 127;
    }

    if (child == 0)
    {
        if (execve(fcmd, command, environ) == -1)
        {
            perror("execve");
            Fr2Darray(command);
            free(fcmd);
            exit(127);
        }
    }
    else
    {
        waitpid(child, &status, 0);
        Fr2Darray(command);
        free(fcmd);
    }

    return WEXITSTATUS(status);
}
