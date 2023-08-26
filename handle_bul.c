#include "shell.h"

/**
 * handle_builtin - Handle Builtin Command
 * @cmd: Parsed Command
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
