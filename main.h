#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/limits.h>
#include <unistd.h>
extern char **environ;

#define DELIMITER " \t\r\n\a"
#define BUFSIZE 1024

void put_unint(unsigned int n);
void put_int(int n);
void show_err(char *line_input, int c, char **array);
void _prerror(char **argv, int c, char **cmd);

int command_chemin(char **command);
char **write_command(char *command);
char *construct(char *tk, char *val);
void creat_envi(char **envi);
void handle_file(char *cmd, int count, FILE *fl, char **array);
void exit_fl_bul(char **command, char *cmd, FILE *fl);
int verify_command(char **tks, char *cmd, int n, char **array);
void rd_fl(char *flname, char **array);
int handle_bul(char **command, int err);
char *_return_envi(char *path_name);
int verify_bul(char **command);

void clean_env(char **environement);
void *fill_an_array(void *a, int el, unsigned int len);
char *_memcpy(char *dest, char *src, unsigned int n);
void *_calloc(unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

char *_strtok(char *string, const char *delimiter);
unsigned int verify_delim(char ch, const char *string);
char *_strncpy(char *dest, char *src, int n);
int _strlen(char *s);
int _putchar(char c);
int _atoi(char *string);
void _puts(char *str);
int _strcmp(char *s1, char *s2);
int _alphabet(int ch);
void array_rev(char *arr, int len);
int intlen(int num);
char *_itoa(unsigned int n);
char *_strcat(char *destination, char *source);
char *_strcpy(char *dest, char *src);
char *_strchr(char *s, char c);
int _strcmpn(const char *s1, const char *s2, size_t n);
char *_strdup(char *str);
void handled_signal(int target_signal);
char *_readline(void);
void _comment(char *bf);
int previous(char *line_input);
int show_hist(char **command, int err);
int show_envi(char **command, int err);
int switch_directory(char **command, int err);
int show_help(char **command, int err);
int write_man(char **command, int err);
void  exit_builtin(char **command, char *line_input, char **array, int ch);
int use_echo(char **command);

/**    structure of the commands */

typedef struct  manips
{
        char *cmd;
        int (*exec)(char **cmd, int err);
} manip_t;
#endif
