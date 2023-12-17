#include "main.h"

/**
 * main - prints the environment using environ
 * @ac: number of command line arguments
 * @av: arguments
 *
 * Return: 0
 */

int main(int ac, char *av[])
{
	int i = 0;

	(void)ac;
	(void)av;

	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]); /* prints in form of "variable=value"*/
		i++;
	}
	return (0);
}
