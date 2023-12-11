#include "shell.h"

/**
 * execute_command - Execute the command with arguments
 * @args: The arguments
 * @envp: The environment variables
 *
 * Return: 0 on success, -1 on failure
 */
int execute_command(char **args, char **envp)
{
	pid_t pid;
	int status;
	char *path = NULL;

	if (execute_builtin(args, envp) == 0)
		return (0);

	path = get_path(args[0]);
	if (path == NULL)
	{
		fprintf(stderr, "%s: command not found\n", args[0]);
		return (-1);
	}

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (-1);
	}
	else if (pid == 0)
	{
		if (execve(path, args, envp) == -1)
		{
			perror("execve");
			free(path);
			return (-1);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			status = WEXITSTATUS(status);
	}

	free(path);
	return (status);
}
