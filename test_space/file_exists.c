#include "shell.h"

/**
 * file_exists - check if the file exist in the system
 * @filename : const char*
 *
 * Return: 0 if success
 */
int file_exists(const char *filename)
{
	struct stat st;

	return (custom_stat(filename, &st) == 0);
}

/**
 * main - check if file_exists works
 * @ac: number of arguments
 * @av: pointer to arguments
 *
 * Return: 1 if fails, 0 if success
 */

int main(int ac, char **av)
{
	int check;

	if (ac != 2)
	{
		printf("Usage: fuckers <file_exists>\n");
		return (1);
	}
	check = file_exists(av[1]);
		if (check != 0)
		{
			printf("Found\n");
			return (0);
		}
	printf("Not found\n");
	return (0);
}
