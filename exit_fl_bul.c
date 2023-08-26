#include "main.h"

/**
 * exit_fl_bul - functions exits the shell
 * @cmd: the argument comd
 * @command: the command itself
 * @fl: file descriptor
 * Return : status
 */
void exit_fl_bul(char **command, char *cmd, FILE *fl)
{
	int status,i;
	
	i = 0;

	if (command[1] == NULL)
	{
		free(cmd);
		free(command);
		fclose(fl);
		exit(errno);
	}
	while (command[1][i])
	{
		if (_alphabet(command[1][i++]) < 0)
		{
			perror("illegal number");
		}
	}
	status = _atoi(command[1]);
	free(cmd);
	free(command);
	fclose(fl);
	exit(status);
}
