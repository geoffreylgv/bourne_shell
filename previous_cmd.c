#include "main.h"
/**
 * previous - get the history
 * @line_input: line
 * Return: 0 , -1
 */
int previous(char *line_input)
{
	char *fl;
	ssize_t file_descriptor, file_write;
	int l;

       	l = 0;	
	fl = ".simple_shell_history";
	if (!fl)
		return (-1);
	file_descriptor = open(fl, O_CREAT | O_RDWR | O_APPEND, 00600);
	
	if (file_descriptor < 0)
		return (-1);
	if (line_input)
	{
		while (line_input[l])
			l++;
		file_write = write(file_descriptor, line_input, l);
		if (file_write < 0)
			return (-1);
	}
	return (1);
}

/**
 * show_hist - shows hist
 * @parsed_command: cmd
 * @statue: statue
 * Return: 0, -1
 */
int show_hist(__attribute__((unused))char ** parsed_command, __attribute__((unused))int statue)
{
	char *fl;
	FILE *file_p;
	char *line, *err;
	size_t l = 0;
	int inc = 0;

	line = NULL;
	fl = ".simple_shell_history";
	file_p = fopen(fl, "r");
	if (file_p == NULL)
	{
		return (-1);
	}
	while ((getline(&line, &l, file_p)) != -1)
	{
		inc++;
		err = _itoa(inc);
		write(STDOUT_FILENO, err, _strlen(err));
		free(err);
		write(STDOUT_FILENO, " ", _strlen(" "));
		write(STDOUT_FILENO, line, _strlen(line));

	}
	if (line)
		free(line);
	fclose(file_p);
	return (0);
}
