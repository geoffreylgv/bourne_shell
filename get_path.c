#include "main.h"

/**
 * location - get the path location
 * @path: the path to env
 * @arg: argument
 *
 * Return: string
 */
char *location(char *path, char *arg)
{
	char *path_copy, *path_token, *file_path;
	char *delimiter = ":"; /**buff*/

	path_copy = strdup(path);
	path_token = strtok(path_copy, delimiter);

	file_path = malloc(_strlen(arg) + _strlen(path_token) + 2);
	/*2 for the / and end of char*/

	while (path_token != NULL)
	{
		strcpy(file_path, path_token);
		strcat(file_path, "/");
		strcat(file_path, arg);
		strcat(file_path, "\0");

		if (file_path)
		{
			path_token = strtok(NULL, delimiter);
		}
	}

	free(file_path);

	/*if (stat(arg, &buff) == 0)*/
		/*checks file is exists and its status return 0 on success*/
		/*return (arg);*/
	return (NULL);
}

/**
 * get_path - get location of all executable command
 * @cmd: the command inputed
 *
 * Return: string (env path)
 */
char *get_path(char *cmd)
{

	char *path;

	/*accessfunction get the PATH name of our system if it's accessible or exists*/;

	if (access("PATH", X_OK) == 0)
	{
		path = getenv("PATH");
	}

	if (path)
	{
		path = location(path, cmd);
		return (path);
	}
	return (NULL);
}

