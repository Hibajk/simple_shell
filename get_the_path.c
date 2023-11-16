#include "shell.h"

/**
 * _path - a function that gets the path of a command
 * @command: the command
 * Return: a dynamically allocated string with the full path
 */

char *_path(char *command)
{
    char *path, *fcmd, *cpath;
    struct stat st;

    int i = 0;

    while (command[i])
    {
        if (command[i] == '/')
        {
            if (stat(command, &st) == 0)
                return _strdup(command);
            return NULL;
        }
        i++;
    }

    path = _geten("PATH");
    if (!path)
        return NULL;

    cpath = strtok(path, ":");
    while (cpath)
    {
        fcmd = malloc(_strlen(cpath) + _strlen(command) + 2);
        if (fcmd)
        {
            _cpystr(fcmd, cpath);
            _catstr(fcmd, "/");
            _catstr(fcmd, command);

            if (stat(fcmd, &st) == 0)
            {
                free(path);
                return fcmd;
            }

            free(fcmd);
            cpath = strtok(NULL, ":");
        }
    }

    free(path);
    return NULL;
}
