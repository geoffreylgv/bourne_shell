#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int _putchar(char c);
int _strlen(char *s);
void _puts(char *str);
int handle_string(char *str);
char *have_location(char *path, char *arg);
char *get_envpath(char *arg);
/*int _builtins(char *arg);*/

#endif
