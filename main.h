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
#define BUFFSIZE 1024

void print_number(unsigned int n);
void print_number_in(int n);
void print_error(char *line, int c, char **argv);
void _prerror(char **argv, int c, char **cmd);

int path_cmd(char **line);
char **write_command(char *command);
char *build(char *token, char *value);
void creat_envi(char **envi);
void handle_file(char *cmd, int count, FILE *fl, char **array);
void exit_fl_bul(char **command, char *cmd, FILE *fl);
int verify_command(char **tks, char *cmd, int n, char **array);
void rd_fl(char *flname, char **array);
int handle_bul(char **command, int err);
char *_getenv(char *name);
int verify_bul(char **command);

void free_env(char **env);
void *fill_an_array(void *a, int el, unsigned int len);
char *_memcpy(char *dest, char *src, unsigned int n);
void *_calloc(unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

char *_strtok(char *str, const char *tok);
unsigned int check_delim(char c, const char *str);
char *_strncpy(char *dest, char *src, int n);
int _strlen(char *s);
int _putchar(char c);
int _atoi(char *s);
void _puts(char *str);
int _strcmp(char *s1, char *s2);
int _alphabet(int ch);
void array_rev(char *arr, int len);
int intlen(int num);
char *_itoa(unsigned int n);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strchr(char *s, char c);
int _strcmpn(const char *s1, const char *s2, size_t n);
char *_strdup(char *str);
void prompt(void);
void signal_to_handel(int sig);
char *_getline(void);
void hashtag_handle(char *buff);
int history(char *input);
int history_dis(char **cmd, int er);
int show_envi(char **command, int err);
int switch_directory(char **command, int err);
int display_help(char **cmd, int er);
int write_man(char **command, int err);
void  exit_builtin(char **command, char *line_input, char **array, int ch);
int print_echo(char **cmd);

/**    structure of the commands */

typedef struct  manips
{
        char *cmd;
        int (*exec)(char **cmd, int err);
} manip_t


#endif
