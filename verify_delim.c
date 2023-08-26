#include "main.h"
/**
 * check_delim - Checks If A Character Match Any Char *
 * @c: Character To Check
 * @str: String To Check
 * Return: 1 Succes, 0 Failed
 */
unsigned int verify_delim(char ch, const char *string)
{
	unsigned int j;

	j = 0;
	while(string[j] != '\0')
	{
		if (ch == string[j])
			return (1);
		j++;
	}
	return (0);
}
