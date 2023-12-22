#include "shell.h"

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
	{
		line[bytes_read - 1] = '\0';
	}
	return (line);
}
