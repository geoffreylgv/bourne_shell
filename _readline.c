#include "main.h"
/**
 * _comment- function that remove things just after comment sign the hashtag (#)
 * @bf: the buffer input gotten
 * Return: NA void
 */
void _comment(char *bf)
{
        int j;

	j = 0;
	while (bf[j] != '\0')
	{
		if (bf[j] == '#')
                {
			bf[j] = '\0';
                        break;
		}
		j++;
        }
}
/**
* _readline - Function like the originaly
* getline useing to get the user entry
* Return: the data or cmd unser entered
*/
char *_readline()
{
	int r, buffsize, j;
	char ch;
	char *bf;

	ch = 0;
	buffsize = BUFSIZE;
	bf = malloc(buffsize);
	if (bf == NULL)
	{
		free(bf);
		return (NULL);
	}

	for (j = 0; ch != EOF && ch != '\n'; j++)
	{
		fflush(stdin);
		r = read(STDIN_FILENO, &ch, 1);
		if (r == 0)
		{
			free(bf);
			exit(EXIT_SUCCESS);
		}
		bf[j] = ch;
		if (bf[0] == '\n')
		{
			free(bf);
			return ("\0");
		}
		if (j >= buffsize)
		{
			bf = _realloc(bf, buffsize, buffsize + 1);
			if (bf == NULL)
			{
				return (NULL);
			}
		}
	}
	bf[j] = '\0';
	_comment(bf);
	return (bf);
}
