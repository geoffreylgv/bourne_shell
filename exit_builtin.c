#include "main.h"
/**
 * exit_builtin -builtin function exit method Exit Statue Shell
 * @command: the command
 * @line_input: input of the user
 * @array: got the name of simpleshell
 * @ch: Number count execution
 * Return: NA
 */
void  exit_builtin(char **command, char *line_input, char **array, int ch)
{
	int st, j;

	j = 0;
	if (command[1] == NULL)
	{
		free(line_input);
		free(command);
		exit(EXIT_SUCCESS);
	}
	while (command[1][j])
	{
		if (_alphabet(command[1][j++]) != 0)
		{
			_prerror(array, ch, command);
			break;
		}
		else
		{
			st = _atoi(command[1]);
			free(command);
			free(line_input);
			exit(st);
		}
	}
}
