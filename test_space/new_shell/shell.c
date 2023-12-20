#define _GNU_SOURCE

#include "shell.h"

/**
 * main - program that mimic a super simple shell)
 *
 * Return: 0
 */

int main(void)
{
	int status = 0;
	char *command = NULL;
	char **tokens = NULL;

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
		{
			printf("$ ");
			fflush(stdout);
		}
		command = read_line();
		tokens = split_line(command);
		status = execute_command(tokens);

		if (status >= 0)
		{
			exit(status);
		}
	}
	free(command);
	free(tokens);
	return (0);
}
