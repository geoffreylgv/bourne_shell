#include "main.h"
/**
 *  _prerror - error handling 
 * @array: array
 * @ch: number of errors
 * @command: Command
 * Return: nothing
 */
void _prerror(char **array, int ch, char **command)
{
	char *err;
       	err = _itoa(ch);

	write(STDOUT_FILENO, array[0], _strlen(array[0]));
	write(STDOUT_FILENO, ": ", _strlen(": "));
	write(STDOUT_FILENO, err, _strlen(err));
	write(STDOUT_FILENO, ": ", _strlen(": "));
	write(STDOUT_FILENO, command[0], _strlen(command[0]));
	write(STDOUT_FILENO, ": Illegal number: ", _strlen(": Illegal number: "));
	write(STDOUT_FILENO, command[1], _strlen(command[1]));
	write(STDOUT_FILENO, "\n", _strlen("\n"));;
	free(err);
}
/**
 * show error - shows the errors
 * @line_input: line input 
 * @count: count 
 * @array: array
 * Return: nothing
 */
void show_err(char *line_input, int count, char **array)
{
	char *err;

	write(STDOUT_FILENO, array[0], _strlen(array[0]));
	write(STDOUT_FILENO, ": ", _strlen(": "));
	err = _itoa(count);
	write(STDOUT_FILENO, err, _strlen(err));
	free(err);
	write(STDOUT_FILENO, ": ", _strlen(": "));
	write(STDOUT_FILENO, line_input, _strlen(line_input));
	write(STDOUT_FILENO, ": not found\n", _strlen(": not found\n"));
}
