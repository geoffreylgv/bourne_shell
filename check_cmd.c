#include "main.h"

/**
 *
 *
 *
 *
 *
 *
 */

int check_cmd(char *cmd)
{
	int i = 0;

	for (i = 0; i < _strlen(cmd); i++)
	{
		if (cmd[i] == '/')
		{
			if(cmd[i + 1] == 'b' && cmd[i + 2] == 'i' && cmd[i + 3] == 'n' && cmd[i + 4] == '/')
			{
				return (1);
			}
		}
	}
	return (0);
}
