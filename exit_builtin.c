#include "main.h"
/**
 * exit_bul - Exit Statue Shell
 * @cmd: Parsed Command
 * @input: User Input
 * @argv:Program Name
 * @c:Excute Count
 * Return: Void (Exit Statue)
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
