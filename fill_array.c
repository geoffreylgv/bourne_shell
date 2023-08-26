#include "main.h"

/**
 * enlarge_arr - fills the array
 * @v: ptr
 * @j: number
 * @l: lenght of j
 * Return: ptr
 */
void *enlarge_arr(void *v, int j, unsigned int l)
{
	char *c = v;
	unsigned int i = 0;

	while (i < l)
	{
		*c = j;
		c++;
		i++;
	}
	return (v);
}
