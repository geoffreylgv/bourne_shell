#include "main.h"

/**
 * _isatty - function that checks if it is a tty
 * Return: NA void
 * Descriptprompt handle_string("student@alxafrica.com $➜  ")
 */
void _isatty(void) {
  if (isatty(0))
    handle_string("alxShell $ ");
}
