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

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
		{
			printf("$ ");
		}
		fflush(stdout);

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
		/*free command? w/ loop*/
		free(args);
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
				/*to modify*/
				fprintf(stderr, "./shell: 1: %s: not found\n", args[0]);
				exit(EXIT_FAILURE);
			}
		}
		wait(&status);
		/* free(args);*/
		return (status);
	}
	fprintf(stderr, "./shell: No such file or directory\n");
	/* free(args);*/
	return (status);
}
