#include "main.h"
/**
 * verify_bul - verifies the builtins
 * @command: command
 * Return: 0 , -1
 *
 */

int verify_bul(char **command)
{
	manip_t exec[] = {
		{"cd", NULL},
		{"help", NULL},
		{"echo", NULL},
		{"history", NULL},
		{NULL, NULL}
	};
	int i = 0;
		if (*command == NULL)
	{
		return (-1);
	}

	while ((exec + i)->cmd)
	{
		if (_strcmp(command[0], (exec + i)->cmd) == 0)
			return (0);
		i++;
	}
	return (-1);
}
