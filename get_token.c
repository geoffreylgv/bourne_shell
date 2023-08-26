#include "main.h"

/**
 * get_token - function to tokenize a
 * nd returns array of cmd
 * @lineptr: char read by user
 *
 * Return: array (string/ char)
 */
char **get_token(char *lineptr, int nchar_read)
{

	int i, tknum;
	char *token, *delimiter, *lineptrcpy;
	char **array;
	
	delimiter = " \n";
	i = 0;
	tknum = 0;
	lineptrcpy = malloc(sizeof(char) * nchar_read);
	if (lineptrcpy== NULL){
            perror("tsh: memory allocation error");
            return (NULL);
        }
	strcpy(lineptrcpy, lineptr);

	token = strtok(lineptr, delimiter);

	while (token != NULL)
	{
            tknum++;
            token = strtok(NULL, delimiter);
        }
	tknum++;


	array = malloc(sizeof(char *) * tknum);
	token = strtok(lineptrcpy, delimiter);
	while (token != NULL)
	{
		array[i] = malloc(sizeof(char) * strlen(token));
            	strcpy(array[i], token);
		token = strtok(NULL, delimiter);
		i++;
	}
	array[i] = NULL;

	free(lineptr);
	free(lineptrcpy);

	return (array);
}
