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
	char *path = NULL;
	char *path_copy = NULL;
	char *full_path = NULL;
	char *token = NULL;

	if (strchr(command, '/') != NULL)
	{
		return (strdup(command));
	}

	path = _getenv("PATH");
	path_copy = strdup(path);
	token = strtok(path_copy, ":");

	free(path);

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
