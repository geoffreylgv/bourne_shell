#include "main.h"

/**
 * put_int - print an int
 * @n:Integer
 * Return: void
 */
void put_int(int num)
{
        unsigned int i;

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

/**
 * _strlen - lenght of string
 * @s:char
 * Return:int
 */

int _strlen(char *s)
{
	int j;

	for (j = 0; s[j] != '\0'; j++)
	{
		continue;
	}
	return (j);
}
/**
 * _strcat - Concat Two String
 * @dest:First String
 * @src:Second String
 * Return:First String + Second String Char *
 */
char *_strcat(char *destination, char *source)
{
	char *str;
       	
	str = destination;
	while (*destination != '\0')
	{
		destination++;
	}

	while (*source != '\0')
	{
		*destination = *source;
		destination++;
		source++;
	}
	*destination = '\0';
	return (str);
}
