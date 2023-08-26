#include "main.h"

/**
 * use_ech - the /bin/echo command original use
 * @command: command passed to pipe
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
