#include "main.h"
/**
 * _strcmpn - Compare a number of char in two strings
 * @s1: string 1
 * @s2: string 2
 * @n: number of char
 *
 * Return: 1 matched , 0 unmatched
 */
int _strcmpn(const char *s1, const char *s2, size_t n)
{
        size_t i;

        if (s1 == NULL)
                return (-1);
        for (i = 0; i < n && s2[i]; i++)
        {
                if (s1[i] != s2[i])
                {
                        return (1);
                }
        }
        return (0);
}
/**
 * _strdup - Duplicate A String
 * @str:String
 * Return: Duplicate String Failed Null
 */
char *_strdup(char *str)
{
	size_t l, j;
	char *s;

	l = _strlen(str);
	s = malloc(sizeof(char) * (l + 1));
	if (!s)
	{
		return (NULL);
	}

	for (j = 0; j <= l; j++)
	{
		s[j] = str[j];
	}

	return (s);
}
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
        return (write(1, &c, 1));
}

char *_itoa(unsigned int n)
{
	int len = 0, i = 0;
	char *s;

	len = intlen(n);
	s = malloc(len + 1);
	if (!s)
		return (NULL);
	*s = '\0';
	while (n / 10)
	{
		s[i] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	s[i] = (n % 10) + '0';
	array_rev(s, len);
	s[i + 1] = '\0';
	return (s);
}
