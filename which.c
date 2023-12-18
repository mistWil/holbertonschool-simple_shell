#include "shell.h"

/**
 * which - Search for the location of an executable command in
 * the directories listed in the PATH environment variable
 * @command: the corresponding command
 *
 * Return: char
 */
char *which(char *command)
{
	char *path = getenv("PATH");
	char *path_copy = custom_strdup(path);
	char *token = strtok(path_copy, ":");
	struct stat st;
	char *full_path;

	while (token != NULL)
	{
		full_path = malloc(strlen(token) + strlen(command) + 2);
		strcpy(full_path, token);
		strcat(full_path, "/");
		strcat(full_path, command);

		if (custom_stat(full_path, &st) == 0)
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
