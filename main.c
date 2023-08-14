#include "main.h"

/**
 * main - A custom implementation of the sh (bourne shell) in C
 * @a: first argument of main
 * @env: environement
 * Return: 0 on success
 */
int main(int a, char **env)
{

	char *lineptr = NULL, *path;
	char *arg[9]/*number of argument*/;
	char *delimiter = " \n";
	size_t n = 0;
	ssize_t nchars_read;
	pid_t child_id;
	int status, i = 0, j = 0, exec;
	(void)a;

	while (1 == 1)
	{
		/*checks if the descriptor refers to a terminal*/
		if (isatty(STDIN_FILENO))
			handle_string("student@alxafricadotcom $➜  ");

		nchars_read = getline(&lineptr, &n, stdin);

		if (nchars_read == -1)
		{
			/*handle_string("Exiting shell ...\n");*/
			free(lineptr);
			/*exit to close the program*/
			exit(0);
		}

		/*interactiv mode*/
		while (lineptr[i])
		{
			if (lineptr[i] == '\n')
				lineptr[i] = 0;
			i++;
		}

		arg[j] = strtok(lineptr, delimiter);/*extract token from a string*/
		child_id = fork();/*create a child process*/


		/*loop through every single token, passe whatever option argument the user will pass*/
		while (arg[j])
		{
			arg[++j] = strtok(NULL, delimiter);
		}

		path = get_path(arg[0]);

		if (child_id < 0)
		{
			handle_string("Failed to forking");
			free(lineptr);
			exit(0);
		}
		else if (child_id == 0)
		{
			exec = execve(path, arg, env);
			if (exec == -1)
				handle_string("The command does not exist!\n");
		}
		else
			wait(&status);/*wait the process to change state*/

		/*handle_string(lineptr);*/
	}
	free(lineptr);
	return (0);
}

