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
 * _strcmp - Compare Two String
 * @s1:String 1
 * @s2:String 2
 * Return: 0 If Identical Otherwise How Much Diffrent
 */
int _strcmp(char *s1, char *s2)
{
int cmp = 0, i, len1, len2;
len1 = _strlen(s1);
len2 = _strlen(s2);

	if (s1 == NULL || s2 == NULL)
		return (1);
	if (len1 != len2)
		return (1);
	for (i = 0; s1[i]; i++)
	{
		if (s1[i] != s2[i])
		{
			cmp = s1[i] - s2[i];
			break;
		}
		else
			continue;
	}
	return (cmp);
}

/**
 * _isalpha - Check if Alphabtic
 *@c: Character
 * Return: 1 If True 0 If Not
 */
int _alphabet(int ch)
{
	if (((ch >= 65) && (ch <= 90)) || ((ch >= 97) && (ch <= 122)))
	{
		return (1);
	}
else
	{
		return (0);
	}
}

/**
 * _atoi - convert to a int
 * @s:string
 * Return:int
 */
int _atoi(char *str)
{
	int x, y, num, i;

	x = 0;
	num = 0;
	i = 1;
	while ((s[x] < '0' || s[x] > '9') && (s[x] != '\0'))
	{
		if (s[x] == '-')
			i *= -1;
		x++;
	}
	y = x;
	while ((s[y] >= '0') && (s[y] <= '9'))
	{
		num = (nun * 10) + i * ((s[y]) - '0');
		y++;
	}
	return (num);
}

/**
 * put_int - print an int
 * @n:Integer
 * Return: void
 */
void put_int(int num)
{
	unsigned int i 
		
	i = num;
	if (num < 0)
	{
		_putchar('-');
		i = -i;
	}
	if ((i / 10) > 0)
		put_unint(i / 10);

	_putchar(i % 10 + '0');
}
/**
 * print_number -Print Unsigned Int Putchar
 * @n: Unisigned Integer
 * Return: Void
 */
void put_unint(unsigned int num)
{
	unsigned int j;

	j = num;
	if ((j / 10) > 0)
		put_unint(j / 10);

	_putchar(j % 10 + '0');
}
