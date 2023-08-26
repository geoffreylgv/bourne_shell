#include "main.h"
/**
 * build - Command builder
 * @tk: token parameter
 * @val: the value parameter
 *
 * Return: Path relative of a command, null otherwise
 */
char *construct(char *tk, char *val)
{
	char *command;
	size_t l;

	l = _strlen(val) + _strlen(tk) + 2;
	command = malloc(sizeof(char) * l);
	if (command == NULL)
	{
		return (NULL);
	}

	memset(command, 0, l);

	command = _strcat(command, val);
	command = _strcat(command, "/");
	command = _strcat(command, tk);

	return (command);
}
