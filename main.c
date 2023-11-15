#include <stdlib.h>
#include "shell.h"
#include <string.h>
#include <stdio.h>

/**
 * main - the main functions
 * @ac: arg count
 * @argv: arguments
 * Return: 0
 */

int main(int ac, char **argv)
{
    int status = 0, nmbr = 0;
    char *line = NULL;
    char **command = NULL;
    
    (void)ac;

    while (1)
    {
        line = prompt_shell();
        if (line == NULL)
        {
            if (isatty(STDIN_FILENO))
                write(STDOUT_FILENO, "\n", 1);
            free(line);
            return status;
        }

        nmbr++;
        command = command_tokenizer(line);
        if (!command)
        {
            free(line);
            continue;
        }

        if (_strcmp(command[0], "exit") == 0)
        {
            free(line);
            Fr2Darray(command);
            exit(status);
        }

        if (_strcmp(command[0], "env") == 0)
            prenv(command, &status);
        else
            status = _exec(command, argv, nmbr);

        free(line);
        Fr2Darray(command);
    }
}