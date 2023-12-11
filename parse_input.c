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

	args = malloc(sizeof(char *));
	if (args == NULL)
	{
		perror("malloc");
		return (NULL);
	}

	token = strtok(input, " \t\r\n");
	while (token != NULL)
	{
		args[i] = strdup(token);
		if (args[i] == NULL)
		{
			perror("strdup");
			free_args(args);
			return (NULL);
		}
		i++;
		args = realloc(args, sizeof(char *) * (i + 1));
		if (args == NULL)
		{
			perror("realloc");
			return (NULL);
		}
		token = strtok(NULL, " \t\r\n");
	}
	args[i] = NULL;
	return (args);
}
