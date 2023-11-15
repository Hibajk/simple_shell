#include "shell.h"

/**
 * _strdup - duplicates a string
 * @str: the string to duplicate
 * Return: a pointer to the duplicated string, or NULL on failure
 */

char *_strdup(const char *str)
{
    if (str == NULL)
        return NULL;

    size_t len = _strlen(str);
    char *ptr = malloc(sizeof(char) * (len + 1));

    if (ptr == NULL)
        return NULL;

    for (size_t i = 0; i <= len; i++)
        ptr[i] = str[i];

    return ptr;
}

/**
 * _strcmp - compares two strings
 * @s1: the first string
 * @s2: the second string
 * Return: an integer less than, equal to, or greater than zero
 * if s1 is found, respectively, to be less than, to match, or be greater
 */

int _strcmp(const char *s1, const char *s2)
{
    while (*s1 && (*s1 == *s2))
    {
        s1++;
        s2++;
    }

    return (int)(*s1) - (int)(*s2);
}

/**
 * _strlen - measures the length of a string
 * @s: the string to measure
 * Return: the length of the string
 */

size_t _strlen(const char *s)
{
    size_t len = 0;

    while (s[len] != '\0')
        len++;

    return len;
}

/**
 * _strcat - concatenates two strings
 * @dest: the destination string
 * @src: the source string
 * Return: a pointer to the resulting string (dest)
 */

char *_strcat(char *dest, const char *src)
{
    char *p = dest;

    while (*p)
        p++;

    while (*src)
    {
        *p = *src;
        p++;
        src++;
    }

    *p = '\0';
    return dest;
}

/**
 * _strcpy - copies a string to another
 * @dest: the destination string
 * @src: the source string
 * Return: a pointer to the resulting string (dest)
 */

char *_strcpy(char *dest, const char *src)
{
    size_t i = 0;

    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }

    dest[i] = '\0';
    return dest;
}
