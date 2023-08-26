#include "main.h"
/**
 * rev_arr - Have array and revere it
 * @array: array gien to reverse
 * @l: array length
 * Return: NA Void
 */
void rev_arr(char *array, int l)
{
	int j;
	char t;

	for (j = 0; j < (l / 2); j++)
	{
		t = array[j];
		array[j] = array[(l - 1) - j];
		array[(l - 1) - j] = t;
	}
}
