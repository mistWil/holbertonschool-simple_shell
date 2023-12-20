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

	while (environ[i] != NULL)
	{
		token = strtok(environ[i], "=");
		if (token == NULL)
		{
			free(token);
			return (NULL);
		}
		if (strcmp(token, name) == 0)
		{
			token = strtok(NULL, "=");
			return (token);
		}
		i++;
	}
	free(token);
	return (NULL);
}
