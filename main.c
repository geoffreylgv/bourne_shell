#include "main.h"

/**
 * main - ALX Simple shell
 * @array: Argument vectors
 * @argc:Argument number
 * Return: status
 */

int main(__attribute__((unused)) int argc, char **array)
{
	char *line_input, **command;
	
	int status, count, st;
	
	status = 1;
	count = 0;
	st = 0;
	if (array[1] != NULL)
		rd_fl(array[1], array);
	signal(SIGINT, handled_signal);
	while (status)
	{
		count++;
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", _strlen("$ "));
		line_input = _readline();
		if (line_input[0] == '\0')
		{
			continue;
		}
		previous(line_input);
		command = write_command(line_input);
		if (_strcmp(command[0], "exit") == 0)
		{
			exit_builtin(command, line_input, array, count);
		}
		else if (verify_bul(command) == 0)
		{
			st = handle_bul(command, st);
			free(command);
			free(line_input);
			command = NULL;
			line_input = NULL;
			continue;
		}
		else
		{
			st = verify_command(command, line_input, count, array);

		}
		free(command);
		free(line_input);
		command = NULL;
		line_input = NULL;
	}
	return (status);
}
