#include "main.h"

/**
 * _strcmp - Compare Two String
 * @s1:String 1
 * @s2:String 2
 * Return: 0 If Identical Otherwise How Much Diffrent
 */
int _strcmp(char *s1, char *s2)
{
	int cmp, i, len1, len2;
	len1 = _strlen(s1);
	len2 = _strlen(s2);

	cmp = 0;
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
int _atoi(char *string)
{
	int x, y, num, i;

	x = 0;
	num = 0;
	i = 1;
	while ((string[x] < '0' || string[x] > '9') && (string[x] != '\0'))
	{
		if (string[x] == '-')
			i *= -1;
		x++;
	}
	y = x;
	while ((string[y] >= '0') && (string[y] <= '9'))
	{
		num = (num * 10) + i * ((string[y]) - '0');
		y++;
	}
	return (num);
}
