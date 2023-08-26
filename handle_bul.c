#include "main.h"

/**
 * handle_bul - handles the commands
 * @command: command
 * @er:statue of last Excute
 * Return: -1 Fail 0 Succes (Return :Excute Builtin)
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
 * dis_env - Display Enviroment Variable
 * @cmd:Parsed Command
 * @er:Statue of Last command Excuted
 * Return:Always 0
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
