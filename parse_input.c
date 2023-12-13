#include "shell.h"

/**
 * parse_input - Parse the input string into arguments
 * @input: The input string
 *
 * Return: An array of arguments (NULL terminated)
 */
char **parse_input(char *input)
{
	char **args = NULL;
	char *token = NULL;
	int i = 0;

	args = malloc(sizeof(char *) * 1024);
	if (args == NULL)
	{
		perror("malloc");
		return (NULL);
	}

	token = strtok(input, " \n");
	while (token != NULL)
	{
		args[i] = _strdup(token);
		if (args[i] == NULL)
		{
			perror("strdup");
			free_args(args);
			return (NULL);
		}
		i++;
		if (args == NULL)
		{
			perror("error");
			return (NULL);
		}
		token = strtok(NULL, " \n");
	}
	args[i] = NULL;
	return (args);
}
