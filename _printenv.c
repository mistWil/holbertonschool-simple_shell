#include "shell.h"

/**
 * _printenv - prints the environment using environ
 * @ac: number of command line arguments
 * @av: arguments
 *
 * Return: 0
 */

int _printenv(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
	return (0);
}
