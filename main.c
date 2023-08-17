#include "main.h"
/**
 * main - A custom implementation of the sh (bourne shell) in C
 *
 * Return: 0 on success
 */
int main(void)
{

        char *lineptr;
        size_t n = 0;
        ssize_t nchars_read;
        char *arr[20];
	char *token;
        int i, st;
        pid_t pid;
	
        /* arr = malloc(sizeof(char *) *1024);*/
        i = 0;
        while (1 == 1)
        {
                handle_string("student@alxafrica.com $➜  ");
                nchars_read = getline(&lineptr, &n, stdin);
                if (nchars_read == -1)
                {
                        handle_string("Exiting shell ...\n");
                        return (-1);
                }

                else if ( nchars_read == 1)
                {
                        handle_string(lineptr);
                        continue;
                }
                else
                {
                       	token = strtok(lineptr, " \t\n");
                        while (token != NULL)
                        {
                                arr[i] = token;
                                token = strtok(NULL, " \t\n");
                                i++;
                        }
                        arr[i] = NULL;
                        pid = fork();

                        if (pid == 0)
                        {
                                if (execve(arr[0], arr, NULL) == -1)
                                {
                                        perror("Error:");
                                        return (-1);
                                }
                        }
                        else
                                wait(&st);
                       /*free(arr);*/
                        i = 0;
                }
        }
        free(lineptr);
        return (0);
}
