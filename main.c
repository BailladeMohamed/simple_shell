#include "shell.h"

/**
 * main - Entry point of the shell program
 * @argc: The argument count
 * @envp: The environment variables
 *
 * Return: Always 0
 */
int main(int argc, char *envp[])
{
	char *input = NULL;
	char **args = NULL;
	int status = 0;
	size_t len = 0;

	(void)argc;

	while (1)
	{
		printf("$ ");
		input = NULL;

		if (getline(&input, &len, stdin) == -1)
		{
			if (isatty(STDIN_FILENO))
				printf("\n");
			break;
		}

		args = parse_input(input);
		if (args != NULL)
		{
			status = execute_command(args, envp);
			free_args(args);
		}
		free(input);
	}

	return (status);
}
