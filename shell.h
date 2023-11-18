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
char **cmd_tok(char *inputString);
int _execution(char **cmd, char **argv, int number);
char *_geten(const char *key);
char *_path(char *cmd);

void free2DArray(char **array);
void perror(char *shelln, char *command, int number);
char *_intoa(int n);
void reverse_str(char *string, int ln);
void printenv(char **cmd, int *sts);
void shell_exit(char **cmd, char **argv, int *sts, int idx);
int pos_number(char *strg);
int atoi(char *strg);

char *_dupstr(char *string)
int _cmpstr(const char *s1, const char *s2);
int _lenstr(char *s);
char *_catstr(char *dest, char *source);
char _cpystr(char *dest, char *source);

#endif
