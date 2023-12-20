#define _GNU_SOURCE

#include "shell.h"

/**
 * read_line - function to read the user inputs
 *
 * Return: pointer to a string with the input content
 */

char *read_line(void)
{
	char *line = NULL;
	size_t buf_size = 0;
	ssize_t bytes_read;

	bytes_read = getline(&line, &buf_size, stdin);
	if (bytes_read == EOF)
	{
		perror("Error");
		free(line);
	}
	line[bytes_read - 1] = '\0';
	return (line);
}
