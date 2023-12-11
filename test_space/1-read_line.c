#include <stdio.h>
#include <stdlib.h>

/**
 * main - Write a program that prints "$ "
 * @ac: number of char
 * @av: argument**
 *
 * Return: 0 if success
 */

int main()
{
	char *line = NULL;
	size_t buffer_size = 0;
	ssize_t bytes_read;

	printf("$ ");
	bytes_read = getline(&line, &buffer_size, stdin);

	if (bytes_read != -1)
		printf("%s", line);

	free(line);
	return (0);
}
