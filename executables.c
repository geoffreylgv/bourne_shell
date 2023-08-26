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
 * echo_bul - Excute Echo Cases
 * @st:Statue Of Last Command Excuted
 * @cmd: Parsed Command
 * Return: Always 0 Or Excute Normal Echo
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
		chemin = return_envi("PATH");
		write(STDOUT_FILENO, chemin, _strlen(chemin));
		write(STDOUT_FILENO, "\n", _strlen("\n"));
		free(chemin);

	}
	else
		return (print_echo(command));

	return (1);
}
/**
 * display_help - Displaying Help For Builtin
 * @cmd:Parsed Command
 * @er: Statue Of Last Command Excuted
 * Return: 0 Succes -1 Fail
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
