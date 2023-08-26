#include "main.h"

/**
 * len_int - lenght of integer
 * @n: integer
 * Return: l  lenght
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
