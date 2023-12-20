#define _GNU_SOURCE

#include "new_shell.h"

/**
 * main - program that mimic a super simple shell)
 *
 * Return: 0
 */

int main(void)
{
	char *line = NULL;
	char **lines = NULL;

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
		{
			printf("$ ");
		}
		fflush(stdout);

		line = read_line();

		lines = malloc(2 * sizeof(char *));
		if (lines == NULL)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}
		lines[0] = line;
		lines[1] = NULL;
		execute_command(lines);
		free(line);
		free(lines);
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
	line[bytes_read - 1] = '\0';
	return (line);
}

/**
 * execute_command - function which execute command
 * find in system
 * @args: pointer**
 *
 * Return: status if success
 */

int execute_command(char **args)
{
	pid_t child_pid;
	int status;

	if ((access(args[0], X_OK) == 0))
	{
		child_pid = fork();

		if (child_pid == -1)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}

		if (child_pid == 0)
		{
			if (execve(args[0], args, environ) == -1)
			{
				fprintf(stderr, "%s: No such file or directory\n", args[0]);
				exit(EXIT_FAILURE);
			}
		}
		wait(&status);
		/* free(args);*/
		return (status);
	}
	fprintf(stderr, "./shell: %s: not found\n", args[0]);
	/* free(args);*/
	return (status);
}
