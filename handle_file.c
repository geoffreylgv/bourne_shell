#include "main.h"
/**
 * handle_file - parsing file
 * @cmd: command 
 * @count: count
 * @fl: file 
 * @array:array
 * Return: nothing
 */
void handle_file(char *cmd, int count, FILE *fl, char **array)
{
	char **command;
	int st = 0;

	command = write_command(cmd);

		if (_strcmpn(command[0], "exit", 4) == 0)
		{
			exit_fl_bul(command, cmd, fl);
		}
		else if (verify_bul(command) == 0)
		{
			st = handle_bul(command, st);
			free(command);
		}
		else
		{
			st = verify_command(command, cmd, count, array);
			free(command);
		}
}
