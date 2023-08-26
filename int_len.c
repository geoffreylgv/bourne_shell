#include "main.h"

/**
 * len_int - gets the length of an int
 * @n: int to get the length
 * Return: integer lenght of int
 */
int len_int(int n)
{
	int l = 0;

	while (n != 0)
	{
		l++;
		n /= 10;
	}
	return (l);
}
