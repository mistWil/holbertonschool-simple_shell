#include "shell.h"

/**
 * execute_command - function which execute command
 * find in system
 * @argv: pointer**
 * @line: raw command line
 *
 * Return: status if success
 */
void execute_command(char *argv[], char *line)
{
	int status, exit_status = 0;
	pid_t child;

	if (access(argv[0], X_OK) != 0)
	{
		fprintf(stderr, "./hsh: 1: %s: not found\n", argv[0]);
		free(argv[0]);
		exit(127);
	}
	child = fork();

	if (child == -1)
	{
		perror("Fail Fork\n");
		exit(0);
	}
	else if (child == 0)
	{
		execve(argv[0], argv, environ);
		free(argv[0]);
		exit(0);
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
		{
			exit_status = WEXITSTATUS(status);
			if (exit_status != 0)
			{
				free(argv[0]);
				free(line);
				exit(2);
			}
		}
	}
}
