#include "shell.h"

/**
 * execute_builtin - Execute a built-in command
 * @args: The arguments
 * @envp: The environment variables
 *
 * Return: 0 if the command is a built-in, -1 otherwise
 */
int execute_builtin(char **args, char **envp)
{
	if (strcmp(args[0], "exit") == 0)
	{
		free_args(args);
		exit(0);
	}
	else if (strcmp(args[0], "env") == 0)
	{
		int i;

		for (i = 0; envp[i] != NULL; i++)
			printf("%s\n", envp[i]);

		return (0);
	}
	return (-1);
}
