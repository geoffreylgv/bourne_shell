#include "main.h"
/**
 * treat_file - PARSE Check Command Fork Wait Excute in Line of File
 * @line: Line From A File
 * @counter:Error Counter
 * @fp:File Descriptor
 * @argv:Program Name
 * Return : Excute A line void
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
