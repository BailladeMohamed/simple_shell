#include "shell.h"

/**
 * get_path - Get the path of the command
 * @command: The command
 *
 * Return: The path of the command, NULL if not found
 */
char *get_path(char *command)
{
	char *path = NULL;
	char *token = NULL;
	char *path_env = NULL;
	struct stat st;

	if (stat(command, &st) == 0)
	{
		if ((st.st_mode & S_IFMT) == S_IFREG && access(command, X_OK) == 0)
			return (strdup(command));
		else
			return (NULL);
	}

	path_env = getenv("PATH");
	if (path_env != NULL)
	{
		token = strtok(path_env, ":");
		while (token != NULL)
		{
			path = malloc(strlen(token) + strlen(command) + 2);
			if (path == NULL)
			{
				perror("malloc");
				return (NULL);
			}
			strcpy(path, token);
			strcat(path, "/");
			strcat(path, command);
			if (stat(path, &st) == 0)
			{
				if ((st.st_mode & S_IFMT) == S_IFREG && access(path, X_OK) == 0)
					return (path);
			}
			free(path);
			token = strtok(NULL, ":");
		}
	}
	return (NULL);
}
