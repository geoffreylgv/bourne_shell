#include "main.h"

/**
 * put_int - give an int
 * @num: number
 * Return: nothing
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
 * put_unint - gives number
 * @num: unsigned int
 * Return: nothing
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
 * _strlen - copy of the strlen
 * @s: string
 * Return: lenght
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
 * _strcat - copy of the strcat
 * @destination: dest
 * @source: src
 * Return: str
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
