#include "main.h"

/**
 * _return_envi - return env
 * @path_name: path
 * Return: val
 */
char *_return_envi(char *path_name)
{
	int x, y, i;
	size_t len1, len2;
	char *val;

	len1 = _strlen(path_name);
	for (x = 0 ; environ[x]; x++)
	{
		if (_strcmpn(path_name, environ[x], len1) == 0)
		{
			len2 = _strlen(environ[x]) - len1;
			val = malloc(sizeof(char) * len2);
			if (!val)
			{
				free(val);
				perror("unable to alloc");
				return (NULL);
			}

			y = 0;
			for (i = len1 + 1; environ[x][i]; i++, y++)
			{
				val[y] = environ[x][i];
			}
			val[y] = '\0';

			return (val);
		}
	}

	return (NULL);
}
