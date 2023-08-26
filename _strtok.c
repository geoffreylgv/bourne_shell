#include "main.h"
/**
 * _strtok - Token A String Into Token (strtrok)
 * @str: String
 * @delim: Delimiter
 * Return: Pointer To The Next Token Or NULL
 */
char *_strtok(char *string, const char *delimiter)
{
	static char *token;
	static char *ch;
	unsigned int j;

	j = 0;
	if (string != NULL)
		ch = string;
	token = ch;
	if (token == NULL)
		return (NULL);
	while (token[j] != '\0')
	{
		if (verify_delim(token[j], delimiter) == 0)
			break;
		j++;
	}
	if (ch[j] == '#' || ch[j] == '\0')
	{
		ch = NULL;
		return (NULL);
	}
	token = ch + j;
	ch = token;
	for (j = 0; ch[j] != '\0'; j++)
	{
		if (verify_delim(ch[j], delimiter) == 1)
			break;
	}
	if (ch[j] == '\0')
		ch = NULL;
	else
	{
		ch[j] = '\0';
		ch = ch + j + 1;
		if (*ch == '\0')
			ch = NULL;
	}
	return (token);
}
