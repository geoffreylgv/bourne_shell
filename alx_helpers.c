#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: character to print
 * Return: On success 1, -1 on fail
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _strlen - count chars
 * @s: data from user
 * Return: The result
 */
int _strlen(char *s)
{
	int i = 0, length = 0;

	while (s[i++])
	{
		length++;
	}

	return (length);
}

/**
 * _puts - prints a string
 * @str: String
 */
void _puts(char *str)
{
	int i = 0;

	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
}

/**
 * handle_string - prints out string
 * @str: string parameter
 *
 * Return: String count char printed
 */
int handle_string(char *str)
{
	int i = 0, count = 0;

	while (str[i])
	{
		count += _putchar(str[i]);
		i++;
	}
	return (count);

}

