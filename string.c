#include "shell.h"

/**
 * _dupstr - duplicates a string
 * @string: the string to duplicate
 * Return: a pointer to the duplicated string, or NULL on failure
 */

char *_dupstr(char *string)
{
	char *ptrn;
	int i, ln = 0;

	if (string == NULL)
		return (NULL);
	while (string[ln])
		ln++;

	ptrn = malloc(sizeof(char) * (ln + 1));
	if (ptrn == NULL)
		return (NULL);
	for (i = 0; i <= ln; i++)
		ptrn[i] = string[i];
	return (ptrn);
}

/**
 * _cmpstr - compares two strings
 * @s1: the first string
 * @s2: the second string
 * Return: an integer less than, equal to, or greater than zero
 * if s1 is found, respectively, to be less than, to match, or be greater
 */

int _cmpstr(const char *s1, const char *s2)
{
while (*s1 && (*s1 == *s2))
{
s1++;
s2++;
}

return ((int)*s1 - (int)*s2);
}

/**
 * _lenstr - measures the length of a string
 * @s: the string to measure
 * Return: the length of the string
 */

int _lenstr(char *s)
{
	int ln = 0;

	while (s[ln])
		ln++;
	return (ln);
}

/**
 * _catstr - concatenates two strings
 * @dest: the destination string
 * @source: the source string
 * Return: a pointer to the resulting string (dest)
 */

char *_catstr(char *dest, char *source)
{
	char *pp = dest;

	while (*pp)
		pp++;
	while (*source)
	{
		*pp = *source;
		pp++;
		source++;
	}
	*pp = '\0';
	return (dest);
}

/**
 * _cpystr - copies a string to another
 * @dest: the destination string
 * @source: the source string
 * Return: a pointer to the resulting string (dest)
 */

char _cpystr(char *dest, char *source)
{
	int i = 0;

	while (source[i])
	{
		dest[i] = source[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
