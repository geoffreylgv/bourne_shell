#include "main.h"
/**
 * handled_signal - handling sig
 * @target_signal: sig
 * Return: nothing
 */
void handled_signal(int target_signal)
{
	if (target_signal == SIGINT)
	{
		write(STDOUT_FILENO, "\n$ ", _strlen("\n$ "));
	}
}
