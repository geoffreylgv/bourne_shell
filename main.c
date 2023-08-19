#include "main.h"
/**
 * main - A custom implementation of the sh (bourne shell) in C
 * @argc: arguments
 * @environment: environment variable
 *
 * Return: 0 on success
 */
int main(int argc, char **environment)
{

        char *lineptr, *path, *token;
        size_t n = 0;
        ssize_t nchars_read;
        char *arr[20];
        int i, st;
        pid_t pid;

	(void)argc;
	
        i = 0;
        while (1 == 1)
        {
		if (isatty(0))
	                handle_string("student@alxafrica.com $➜  ");
                nchars_read = getline(&lineptr, &n, stdin);
                if (nchars_read == -1)
                {
                        exit(0);
                }

                else if ( nchars_read == 1)
                {
                        handle_string(lineptr);
                        continue;
                }
                else
                {
			i = 0;
                       	token = strtok(lineptr, " \t\n");
                        while (token != NULL)
                        {
                                arr[i] = token;
                                token = strtok(NULL, " \t\n");
                                i++;
                        }
                        arr[i] = NULL;

			path = get_envpath(arr[0]);/*getpathorcmd*/
			if (path == NULL)
			{
				if (handle_exit(arr) != 0)
					continue;
				handle_string("Command not found\n");
				continue;
			}
                        pid = fork();

                        if (pid == 0)
                        {
                                if (execve(path, arr, environment) == -1)
                                {
                                        perror("Error:");
                                        return (-1);
                                }
                        }
                        else
                                wait(&st);
                }
        }
        free(path);
	free(lineptr);
        return (0);
}

