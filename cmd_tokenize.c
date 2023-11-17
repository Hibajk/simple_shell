#include "shell.h"
#include <string.h>
#include <stdlib.h>

/**
 * cmd_tok - tokenizes a string into an array of strings
 * @inputString: input string to be tokenized
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **cmd_tok(char *inputString)
{
	char *token = NULL, *duplicate = NULL, **cmd_arr = NULL;
	int token_count = 0;
	int i = 0;

	if (!inputString)
		return (NULL);

	duplicate = _strdup(inputString);
	token = strtok(duplicate, " \t\n");
	if (token == NULL)
	{
		free(inputString);
		free(duplicate);
		return (NULL);
	}

	while (token)
	{
		token_count++;
		token = strtok(NULL, " \t\n");
	}
	free(duplicate);

	cmd_arr = malloc(sizeof(char *) * (token_count + 1));
	if (cmd_arr == NULL)
	{
		free(inputString);
		return (NULL);
	}
	token = strtok(inputString, " \t\n");
	while (token)
	{
		cmd_arr[i] = _strdup(token);
		token = strtok(NULL, " \t\n");
		i++;
	}

	free(inputString);
	cmd_arr[i] = NULL;
	return (cmd_arr);
}
