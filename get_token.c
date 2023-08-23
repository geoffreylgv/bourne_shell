#include "main.h"

/**
 * get_token - function to tokenize a
 * nd returns array of cmd
 * @lineptr: char read by user
 *
 * Return: array (string/ char)
 */
char **get_token(char *lineptr)
{

	int i;
	char *token;
	char **array;

	i = 0;
	array = malloc(sizeof(char) * 1);
	token = strtok(lineptr, " \t\n");
	while (token != NULL)
	{
		array = realloc(array, sizeof(token) * (i + 1));
		array[i] = token;
		token = strtok(NULL, " \t\n");
		i++;
	}
	array[i] = NULL;

	return (array);
}
