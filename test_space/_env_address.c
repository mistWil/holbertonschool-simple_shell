#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

extern char **environ;

/**
 * main - prints the environment addresses using environ and env
 * @ac: number of command line arguments
 * @av: arguments
 * @env: environment
 *
 * Return: 0
 */

int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;

	printf("Address of env is: %p\n", (void *)&env);
	printf("Address of environ is: %p\n", (void *)&environ);

	return (0);
}
