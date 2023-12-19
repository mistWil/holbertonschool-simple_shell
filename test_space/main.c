#include "shell.h"

/**
 * main - main function to simple shell program
 * @void: no
 *
 * Return: 0 if success
 */
int main(void)
{
	char *line;
	char **args;
	int status;

	do {
		printf("cisfun$ ");
		line = read_line();
		args = split_line(line);
		status = execute_command(args);

		free(line);
		free(args);
	} while (status);

	return (0);
}
