#include "main.h"

/**
 * have_location - have the path location by arg
 * @path: the path
 * @arg: the argument
 *
 * Return: charrr-- location
 */
char *have_location(char *path, char *arg)
{
	char *copy_path, *tokenize_path;
	char *delimiter = ":", *file_path;

	copy_path = strdup(path);
	tokenize_path = strtok(copy_path, delimiter);

	file_path = malloc(_strlen(arg) + _strlen(tokenize_path) + 2);
	while (tokenize_path != NULL)
	{
		strcpy(file_path, tokenize_path);
		strcat(file_path, "/");
		strcat(file_path, arg);
		strcat(file_path, "\0");

		if (access(file_path, X_OK) == 0)
		{
			return (file_path);
		}
		tokenize_path = strtok(NULL, delimiter);
	}
	free(file_path);
	free(copy_path);

	return (NULL);
}

/**
 * get_envpath - get the path $PATH
 * @arg: the argument
 *
 * Return: char- path command
 */
char *get_envpath(char *arg)
{
	char *path;

	path = getenv("PATH");

	if (path)
	{
		path = have_location(path, arg);
		return (path);
	}

	return (NULL);
}
