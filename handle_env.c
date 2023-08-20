#include "main.h"

/**
 * handle_env - prints environment variable
 * @arg: argumen
 *
 * Return: void
 */
int handle_env(char **arg, char **env)
{
	int i;

	if (strcmp(arg[0], "env") == 0)
	{
		handle_string(env[3]);
		handle_string("-----------");
		for (i = 0; env[i] != NULL; i++)
			handle_string(env[i]);
		return (1);
	}
	return (0);
}
