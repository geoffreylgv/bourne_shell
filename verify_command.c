#include "main.h"
/**
 * verify_command - verify.s command like execute wait or fork
 *
 * @command: the command sent
 * @lineptr: the line user entered(getine)
 * @ch: number time command not found
 * @array: array par
 * Return: 1 command Null, -1 Wrong Command 0 Command Excuted
 */
int verify_command(char **command, char *line_input, int ch, char **array)
{
	pid_t pd;
	int st;

	if (*command == NULL)
	{
		return (-1);
	}

	pd = fork();
	if (pd == -1)
	{
		perror("Error");
		return (-1);
	}

	if (pd == 0)
	{
		if (_strcmpn(*command, "./", 2) != 0 && _strcmpn(*command, "/", 1) != 0)
		{
			command_chemin(command);
		}

		if (execve(*command, command, environ) == -1)
		{
			show_err(command[0], ch, array);
			free(line_input);
			free(command);
			exit(EXIT_FAILURE);
		}
		return (EXIT_SUCCESS);
	}
	wait(&st);
	return (0);
}
