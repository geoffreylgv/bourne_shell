#include "main.h"

/**
 * main - A custom implementation of the sh (bourne shell) in C
 *
 * Return: 0 on success
 */
int main(void)
{

	char *lineptr;
	size_t n = 0;
	ssize_t nchars_read;

	while (1 == 1)
	{
		handle_string("student@alxafrica.com $➜  ");
		nchars_read = getline(&lineptr, &n, stdin);
		if (nchars_read == -1)
		{
			handle_string("Exiting shell ...");
			return (-1);
		}

		else if ( nchars_read == 1)
			handle_string( lineptr);
		else
		{
			handle_string(lineptr);
			handle_string("\n");
		}
	}
	free(lineptr);
	return (0);
}

