#include "main.h"

/**
 * print_echo - Excute Normal Echo
 * @cmd: Parsed Command
 * Return: 0 Succes -1 Fail
 */
int use_echo(char **command)
{
	int st;
	pid_t p;

	p = fork();
	if (p == 0)
	{
	if (execve("/bin/echo", command, environ) == -1)
	{
		return (-1);
	}
		exit(EXIT_FAILURE);
	}
	else if (p < 0)
	{
		return (-1);
	}
	else
	{
		do {
			waitpid(p, &st, WUNTRACED);
		} while (!WIFEXITED(st) && !WIFSIGNALED(st));
	}
	return (1);
}
