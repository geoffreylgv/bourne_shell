#include "main.h"
/**
 * check_cmd - Excute Simple Shell Command (Fork,Wait,Excute)
 *
 * @cmd:Parsed Command
 * @input: User Input
 * @c:Shell Excution Time Case of Command Not Found
 * @argv:Program Name
 * Return: 1 Case Command Null -1 Wrong Command 0 Command Excuted
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
