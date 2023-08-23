#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

extern char **environ;

void _isatty(void);
int _putchar(char c);
void _puts(char *str);
int _strlen(char *s);
int handle_string(char *str);
char *have_location(char *path, char *arg);
char *get_envpath(char *arg);
int handle_exit(char **arg);
int handle_env(char **arg, char **env);
ssize_t _getline(char *lineptr);
char **get_token(char *lineptr);
char *run_command(char **array);

#endif
