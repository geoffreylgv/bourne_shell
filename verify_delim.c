#include "main.h"
/**
 * verify_delim - verify.s the delimiter matches the char specified
 * @ch: whom is going to be checked
 * @string: the delimiter string
 * Return: 1 Succes, 0 Fail
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
