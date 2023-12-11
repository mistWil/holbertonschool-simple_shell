#include <stdio.h>
#include <stdlib.h>

/**
 * main - write all the arguments
 *
 * @ac: number of arguments
 * @av: pointer to an array of string
 *
 * Return: 0
 */

int main(int ac, char **av)
{
	int i = 0;

	if (av == NULL || ac < 1)
		return (1);

	while (av[i] != NULL)
	{
		printf("%s\n", av[i]);
		i++;
	}
	return (0);
}
