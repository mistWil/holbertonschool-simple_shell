#include "main.h"

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

/**
 * main - print a environment variable
 * @ac: number of arguments
 * @av: arguments
 *
 * Return: 0
 */

int main(int ac, char **av)
{
	char *env = NULL;

	if (ac != 2)
	{
		printf("Usage: _getenv <environment_variable>\n");
		exit(EXIT_FAILURE);
	}
	env = getenv(av[1]);
	printf("The environment variable is: %s\n", env);
	return (0);
}
