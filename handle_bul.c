#include "main.h"

/**
 * handle_bul - handles the commands
 * @command: command
 * @er: error
 * Return: 0 , -1
 */

int handle_bul(char **command, int err)
{
	int i;
	manip_t man[] = {
		{"cd", switch_directory},
		{"env", show_envi},
		{"help", show_help},
		{"echo", write_man},
		{"history", show_hist},
		{NULL, NULL}
	};

	i = 0;

	while ((man + i)->cmd)
	{
		if (_strcmp(command[0], (man + i)->cmd) == 0)
		{
			return ((man + i)->exec(command, err));
		}
		i++;
	}
	return (-1);
}

/**
 * show_envi - shows the env variable
 * @command: command
 * @err: status
 * Return: 0
 */
int show_envi(__attribute__((unused)) char **command, __attribute__((unused)) int err)
{
	size_t j;
	int lenght;

	j = 0;
	while (environ[j] != NULL)
	{
		lenght = _strlen(environ[j]);
		write(1, environ[j], lenght);
		write(STDOUT_FILENO, "\n", 1);
		j++;
	}
	return (0);
}
