#define _GNU_SOURCE

#include "shell.h"

/**
 * main - program that mimic a super simple shell)
 *
 * Return: 0
 */
int main(void)
{
	char *user_input = NULL, *line = NULL;
	char **args = NULL;
	ssize_t bytes_read;
	size_t buff_size = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
			printf("$ ");
		fflush(stdout);
		bytes_read = getline(&user_input, &buff_size, stdin);
		if (bytes_read == EOF)
			free(user_input), exit(0);
		line = user_input;
		if (bytes_read > 0 && line[bytes_read - 1] == '\n')
		{
			line[bytes_read - 1] = '\0';
			continue;
		}
		args = split_line(line);
		if (args[0] == NULL)
		{
			free(line);
			free(args);
			continue;
		}
		if (strchr(args[0], '/') != NULL)
			execute_command(args);
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
