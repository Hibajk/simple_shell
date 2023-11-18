#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include "shell.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

extern char **environ;

char *pro_shell(void);
char **cmd_tok(const char *line);
int _execution(char **command, char **argv, int nmbr);
char *_geten(const char *key);
char *_path(char *command);

void freearr(char **arr);
void perror(char *sname, char *cmd, int nmbr);
char *_intoa(int n);
void reverse_str(char *str, int len);
void printenv(char **command, int *status);
void shell_exit(char **command, char **argv, int *status, int idx);
int positive_int(const char *str);
int _atoi(const char *str);

char *_dupstr(const char *str);
int _cmpstr(const char *s1, const char *s2);
size_t _lenstr(const char *s);
char *_catstr(char *dest, const char *src);
char *_cpystr(char *dest, const char *src);

#endif
