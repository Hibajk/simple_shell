#include "shell.h"

/**
 * _execution - function that executes a command
 * @command: command to execute
 * @argv: name of the shell
 * @nmbr: a counter
 * Return: return the status
 */

int _execution(char **command, char **argv, int nmbr)
{
    char *fcmd;
    pid_t child;
    int status;

    fcmd = _path(command[0]);
    if (!fcmd)
    {
        perror(argv[0], command[0], nmbr);
        free(fcmd);
        freearr(command);
        return 127;
    }

    child = fork();
    if (child == -1)
    {
        perror("fork");
        free(fcmd);
        freearr(command);
        return 127;
    }

    if (child == 0)
    {
        if (execve(fcmd, command, environ) == -1)
        {
            perror("execve");
            freearr(command);
            free(fcmd);
            exit(127);
        }
    }
    else
    {
        waitpid(child, &status, 0);
        freearr(command);
        free(fcmd);
    }

    return WEXITSTATUS(status);
}
