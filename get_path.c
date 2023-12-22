#include "shell.h"

/**
 * get_path - Search for the location of an executable command in
 * the directories listed in the PATH environment variable
 * @command: the corresponding command
 *
 * Return: char
 */
char *get_path(char *command)
{
	char *path = _getenv("PATH");
	char *path_copy = strdup(path);
	char *token = strtok(path_copy, ":");
	char *full_path;

	while (token != NULL)
	{
		full_path = malloc(strlen(token) + strlen(command) + 2);
		if (full_path == NULL)
		{
			perror("Malloc is NULL");
			return (NULL);
		}

		sprintf(full_path, "%s/%s", token, command);

		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return (full_path);
		}

		free(full_path);
		token = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}
