#include "main.h"

/**
 * handle_exit - handles the exit command
 * @arg: the command inout from user
 *
 * Return: success interggg --
 */
int handle_exit(char **arg)
{
	if (strcmp(arg[0], "exit") == 0)
		exit(0);
	return (0);
}
