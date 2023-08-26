#include "main.h"

/**
 * clean_env - clean env
 * @environement:  env variable
 * Return: nothing
 */
void clean_env(char **environement)
{
	int k;

	for (k = 0; environement[k]; k++)
	{
		free(environement[k]);
	}
}

/**
 * _memcpy - memcpy
 * @destination:  dest ptr
 * @source: src ptr
 * @n: number size 
 * Return: Void Pointer
 */
char *_memcpy(char *destination, char *source, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		destination[i] = source[i];
	}
	return (destination);
}
