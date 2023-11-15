#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

extern char **environ;

char *prompt_shell(void);
char **command_tokenizer(const char *line);
int _exec(char **command, char **argv, int nmbr);
char *_getenv(const char *key);
char *_getpath(char *command);

void Fr2Darray(char **arr);
void prerror(char *sname, char *cmd, int nmbr);
char *_itoa(int n);
void reverse_string(char *str, int len);
void prenv(char **command, int *status);
void exit_shell(char **command, char **argv, int *status, int idx);
int positive_num(const char *str);
int _atoi(const char *str);

char *_strdup(const char *str);
int _strcmp(const char *s1, const char *s2);
size_t _strlen(const char *s);
char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, const char *src);

#endif
