#include "shell.h"

/**
 * _getenv - get the environment variable corresponding to the name
 * @name: name to search in the environment
 *
 * Return: name of the environment or NULL
 */

char *_getenv(const char *name)
{
	int i = 0;
	char *token;
	char *copy_env = NULL;
	char *copy_path = NULL;

	while (environ[i] != NULL)
	{
		copy_env = strdup(environ[i]);
		token = strtok(copy_env, "=");
		if (token == NULL)
		{
			free(copy_env);
			return (NULL);
		}
		if (strcmp(token, name) == 0)
		{
			token = strtok(NULL, "=");
			copy_path = strdup(token);
			free(copy_env);
			return (copy_path);
		}
		i++;
		free(copy_env);
	}
	return (NULL);
}
