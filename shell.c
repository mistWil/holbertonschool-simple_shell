#define _GNU_SOURCE

#include "shell.h"

/**
 * main - program that mimic a super simple shell)
 *
 * Return: 0
 */

int main(void)
{
	char *line = NULL;
	char **args = NULL;
	ssize_t bytes_read;
	size_t buff_size = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
		{
			printf("$ ");
		}
		fflush(stdout);

		bytes_read = getline(&line, &buff_size, stdin);
		line = read_line();

		args = split_line(line);
		if (args[0] == NULL)
		{
			free(line);
			free(args);
			continue;
		}
		if (strchr(args[0], '/') != NULL)
		{
			execute_command(args);
		}
		else
		{
			args[0] = get_path(args[0]);
			execute_command(args);
		}

		free(line);
		free_args(args);
	}
	free(line);
	return (0);
}
