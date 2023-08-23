#include "main.h"

/**
 * handle_env - prints environment variable
 * @arg: argument
 * @env: environement
 *
 * Return: void
 */
int handle_env(char **arg, char **env)
{
	int i;

	if (strcmp(arg[0], "env") == 0)
	{
		for (i = 0; env[i] != NULL; i++)
			handle_string(env[i]);
		return (1);
	}
	return (0);
}
