#include "main.h"

/**
 * path_cmd -  Search In $PATH For Excutable Command
 * @cmd: Parsed Input
 * Return: 1  Failure  0  Success.
 */
int command_chemin(char **command)
{
	char *chemin, *val, *command_path;
	struct stat buffer;

	chemin = _return_envi("PATH");
	val = _strtok(chemin, ":");
	while (val != NULL)
	{
		command_path = construct(*command, val);
		if (stat(command_path, &buffer) == 0)
		{
			*command = _strdup(command_path);
			free(command_path);
			free(chemin);
			return (0);
		}
		free(command_path);
		val = _strtok(NULL, ":");
	}
	free(chemin);

	return (1);
}
