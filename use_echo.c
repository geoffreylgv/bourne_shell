#include "main.h"

/**
 * print_echo - Excute Normal Echo
 * @cmd: Parsed Command
 * Return: 0 Succes -1 Fail
 */
int use_echo(char **command)
{
	int st;
	pid_t pid;

	pid = fork();
	if (pid == 0)
	{
	if (execve("/bin/echo", cmd, environ) == -1)
	{
		return (-1);
	}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		return (-1);
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}
