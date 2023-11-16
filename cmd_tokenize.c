#include "shell.h"
#include <string.h>
#include <stdlib.h>

/**
 * cmd_tok - tokenizes a string into an array of strings
 * @line: input string
 * Return: a pointer to an array of strings, or NULL on failure
 */

char **cmd_tok(const char *line)
{
    char *token, *dup;
    char **command;
    int cnt = 0;
    int i = 0;

    if (!line)
        return NULL;

    dup = _strdup(line);
    if (!dup)
        return NULL;

    token = strtok(dup, " \t\n");
    if (!token)
    {
        free(dup);
        return NULL;
    }

    while (token)
    {
        cnt++;
        token = strtok(NULL, " \t\n");
    }

    free(dup);
    command = malloc(sizeof(char *) * (cnt + 1));
    if (!command)
        return NULL;

    token = strtok(line, " \t\n");
    while (token)
    {
        command[i] = _strdup(token);
        if (!command[i])
        {
            free_2d_array(command);
            return NULL;
        }
        token = strtok(NULL, " \t\n");
        i++;
    }

    command[i] = NULL;
    return command;
}
