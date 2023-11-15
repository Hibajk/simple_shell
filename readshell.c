#include "shell.h"

/**
 * prompt_shell - reads a line from the user and prints a prompt
 *
 * Return: the line read from the user, or NULL on failure
 */

char *prompt_shell(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read_chars;

    if (isatty(STDIN_FILENO))
        write(STDOUT_FILENO, "$ ", 2);

    read_chars = getline(&line, &len, stdin);

    if (read_chars == -1)
    {
        free(line);
        return NULL;
    }

    return line;
}
