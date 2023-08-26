#include "main.h"

/**
 * switch_directory - switches dirc
 * @command: cmd
 * @er: execution statue
 * Return: 0 , 1
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

	if (dir_val != -1)
	{
		getcwd(path_wd, sizeof(path_wd));
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", path_wd, 1);
	}
	else if (dir_val == -1)
        {
                perror("hsh");
                return (-1);
        }
	return (0);
}
/**
 * write_man - writes path
 * @st: status
 * @command: command
 * Return: exec or 0
 */
int write_man(char **command, int st)
{
	unsigned int pid;
	char *chemin;
       
	pid= getppid();

	if (_strcmpn(command[1], "$?", 2) == 0)
	{
		put_int(st);
		write(STDOUT_FILENO, "\n", _strlen("\n"));
	}
	else if (_strcmpn(command[1], "$$", 2) == 0)
	{
		put_int(pid);
		write(STDOUT_FILENO, "\n", _strlen("\n"));

	}
	else if (_strcmpn(command[1], "$PATH", 5) == 0)
	{
		chemin = _return_envi("PATH");
		write(STDOUT_FILENO, chemin, _strlen(chemin));
		write(STDOUT_FILENO, "\n", _strlen("\n"));
		free(chemin);

	}
	else
		return (use_echo(command));

	return (1);
}
/**
 * show_help - show help
 * @command: command
 * @err: execution
 * Return: 0 , -1
 */
int show_help(char **command, __attribute__((unused))int err)
{
	int fl, file_write, file_read;
	char ch;
	
	file_read = 1;
	fl = open(command[1], O_RDONLY);
	if (fl < 0)
	{
		perror("Error");
		return (0);
	}
	while (file_read > 0)
	{
		file_read = read(fl, &ch, 1);
		file_write = write(STDOUT_FILENO, &ch, file_read);
		if (file_write < 0)
		{
			return (-1);
		}
	}
	_putchar('\n');
	return (0);
}
