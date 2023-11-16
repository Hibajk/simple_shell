#include "shell.h"

/**
 * _geten - function that gets the value of an environment variable
 * @key: the name of the environment variable
 * Return: the value of the environment variable, or NULL if not found
 */

char *_geten(const char *key)
{
    char *tmp, *env_key, *value, *env;
    int i = 0;

    while (environ[i])
    {
        tmp = _strdup(environ[i]);
        env_key = strtok(tmp, "=");

        if (_strcmp(env_key, key) == 0)
        {
            value = strtok(NULL, "\n");
            env = _strdup(value);
            free(tmp);
            return env;
        }

        free(tmp);
        i++;
    }

    return NULL;
}
