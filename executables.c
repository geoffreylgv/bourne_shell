#include "main.h"

/**
 * change_dir - Change Dirctorie
 * @cmd: Parsed Command
 * @er: Statue Last Command Excuted
 * Return: 0 Succes 1 Failed (For Old Pwd Always 0 Case No Old PWD)
 */
int switch_directory(char **command, __attribute__((unused))int err)
{
	int dir_val = -1;
	char path_wd[PATH_MAX];

	if (command[1] == NULL)
		dir_val = chdir(getenv("HOME"));
	else if (_strcmp(command[1], "-") == 0)
	{
		dir_val = chdir(getenv("OLDPWD"));
	}
	else
		dir_val = chdir(command[1]);

	if (dir_val == -1)
	{
		perror("hsh");
		return (-1);
	}
	else if (dir_val != -1)
	{
		getcwd(path_wd, sizeof(path_wd));
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", path_wd, 1);
	}
	return (0);
}
