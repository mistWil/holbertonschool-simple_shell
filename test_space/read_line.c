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
	size_t bufsize = 0;

	getline(&line, &bufsize, stdin);
	return (line);
}
