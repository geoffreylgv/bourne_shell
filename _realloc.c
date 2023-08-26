#include "main.h"

/**
 * _realloc - realloc
 *@pointer: Pointer
 *@o_s: o string
 *@n_s: n string
 *Return: out
 */
void *_realloc(void *pointer, unsigned int o_s, unsigned int n_s)
{
	void *out;

	if (n_s == o_s)
		return (pointer);
	if (n_s == 0 && pointer)
	{
		free(pointer);
		return (NULL);
	}
	out = malloc(n_s);
	if (out == NULL)
		return (NULL);
	if (pointer == NULL)
	{
		enlarge_arr(out, '\0', n_s);
		free(pointer);
	}
	else
	{
		_memcpy(out, pointer, o_s);
		free(pointer);
	}
	return (out);

}
