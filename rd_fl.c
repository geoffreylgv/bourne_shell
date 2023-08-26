#include "main.h"
/**
 * rd_fl - Reads the file comman
 * @flname: Filename
 * @array :array
 * Return: -1 ,  0
 */

void rd_fl(char *flname, char **array)
{
	FILE *fl;
	char *cmd = NULL;
	size_t len = 0;
	int count = 0;

	fl = fopen(filename, "r");
	if (fl == NULL)
	{
		exit(EXIT_FAILURE);
	}
	while ((getline(&cmd, &len, fl)) != -1)
	{
		count++;
		handle_file(cmd, count, fl, array);

	}
	if (cmd)
		free(cmd);
	fclose(fl);
	exit(0);
}
