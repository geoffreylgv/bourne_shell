#include "main.h"

/**
 * write_command - write the command line
 * @line_input: input line
 * Return: Array
 */
char **write_command(char *line_input)
{
	char **tks;
	char *tk;
	int i, buffsize;
       
	buffsize = BUFSIZE;

	if (line_input == NULL)
		return (NULL);
	tks = malloc(sizeof(char *) * buffsize);
	if (!tks)
	{
		perror("HSH");
		return (NULL);
	}

	tk = _strtok(line_input, "\n ");
	for (i = 0; tk; i++)
	{
		tks[i] = tk;
		tk = _strtok(NULL, "\n ");
	}
	tks[i] = NULL;

	return (tks);
}
