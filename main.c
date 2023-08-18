#include "main.h"

int main(int ar, char **environment)
{
	char *prompt = "alx $ ", *path, *buffer = NULL;
	char *argum[20], *delimiter = " \n";
	size_t buffersize = 0;
	ssize_t nchars;
	pid_t childpid;
	int i, j, state, execute;

	(void)ar;

	while (1 == 1)
	{
		if (isatty(0))
			handle_string(prompt);
		nchars = getline(&buffer, &buffersize, stdin);

		if (nchars == -1)
		{
			break;/*exitshell*/
		}

		i = 0;
		while (buffer[i])
		{
			if (buffer[i] == '\n')
			{
				buffer[i] = 0;
			}
			i++;
		}

		j = 0;
		argum[j] = strtok(buffer, delimiter);
		while (argum[j])
		{
			argum[++j] = strtok(NULL, delimiter);
		}

		path = get_envpath(argum[0]);/*get the path*/

		if (path == NULL)
		{
			handle_string("Command not found\n");
			continue;
		}

		childpid = fork();
		if (childpid < 0)
		{
			handle_string("fork function failed for the childpid");
			free(buffer);
			return (-1);
		}
		else if (childpid == 0)
		{
			execute = execve(path, argum, environment);
			if (execute == -1)
			{
				handle_string("command doesn't exist\n");
			}
		}
		else
			wait(&state);
	}
	free(buffer);
	return (0);
}
