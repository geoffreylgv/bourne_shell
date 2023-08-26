#include "main.h"
/**
 * signal_to_handel - Handle ^C
 * @sig:Captured Signal
 * Return: Void
 */
void handled_signal(int target_signal)
{
	if (target_signal == SIGINT)
	{
		write(STDOUT_FILENO, "\n$ ", _strlen("\n$ "));
	}
}
