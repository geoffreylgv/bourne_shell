#include "main.h"
/**
 *  array_rev - Reverse Array
 * @arr:Array To Reverse
 * @len:Length Of Array
 * Return: Void(Reverse Array)
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
