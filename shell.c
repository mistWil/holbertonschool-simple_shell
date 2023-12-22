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

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
		{
			printf("$ ");
			fflush(stdout);
		}

		line = read_line();
		split_line(line);
		free(line);
	}
	return (0);
}

/**
 * read_line - function to read the user inputs
 * @void
 *
 * Return: char
 */

char *read_line(void)
{
	char *line = NULL;
	ssize_t bytes_read;
	size_t buff_size = 0;

	bytes_read = getline(&line, &buff_size, stdin);
	if (bytes_read == EOF)
	{
		free(line);
		exit(0);
	}
	if (bytes_read > 0 && line[bytes_read - 1] == '\n')
		line[bytes_read - 1] = '\0';
	return (line);
}
