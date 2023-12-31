#include "main.h"
/**
 * _strcmpn - justt like strcmp
 * @s1: s 1
 * @s2: s 2
 * @n: number to take
 *
 * Return: 1, 0
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
 * _strdup - just like strdup
 * @str: str
 * Return: just like strdup
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

/**
 * _itoa - just like itoa
 * @n: number
 * Return: string
 */
char *_itoa(unsigned int n)
{
	int len = 0, i = 0;
	char *s;

	len = len_int(n);
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
	rev_arr(s, len);
	s[i + 1] = '\0';
	return (s);
}
