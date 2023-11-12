#include "shell.h"
#include <string.h>
#include <stdlib>

/**
 * tokenize_Command - Breaks down a string into an array of strings
 * @inputstr: the input string to be tokenized
 * Return: pointer to an array of strings
 */

char **tokenize_Command(char *inputstr)
{
	char *mytoken = NULL;
	char *mydup = NULL;
	char **cmd = NULL;
	int cnt = NULL;
	int i = NULL;

	if (!inputstr)
		return (NULL);
	mydup = _strdup(inputstr);
	token = strtok(mydup, " \t\n");
	if (token == NULL)
	{
		free(inputstr), inputstr = NULL;
		free(mydup), mydup = NULL;
		return (NULL);
	}
	while (token)
	{
		cnt++;
		mytoken = strtok(NULL, " \t\n");
	}
	free(mydup), mydup = NULL;

	cmd = malloc(sizeof(char *) * (cnt + 1));
	if (cmd == NULL)
	{
		free(inputstr), inputstr = NULL;
		return (NULL);
	}
	mytoken = strtok(inputstr, "\t\n");
	while (mytoken)
	{
		cmd[i] = _strdup(mytoken);
		mytoken = strtok(NULL, "\t\n");
		i++;
	}
	free(inputstr), inputstr = NULL;
	cmd[i] = NULL;
	return (cmd);
}
