#include "main.h"

/**
 * run_command - function that runs commands given
 * @array: command given in an array
 *
 * Return: the path to free after
 */
char *run_command(char **array)
{
	int st;
	pid_t pid;
	char *path;

	if (check_cmd(array[0]) == 0)
		path = get_envpath(array[0]);
	else
		path = array[0];
	if (path == NULL)
	{
		if (handle_exit(array) != 0)
		{
		}
		else if (handle_env(array, environ) != 0)
		{
			perror(" : not found ");
		}
	}
	pid = fork();

	if (pid == 0)
	{
		if (execve(path, array, environ) == -1)
		{
			perror("Error:");
			exit(0);
		}
	}
	else
		wait(&st);
	return (path);
}
