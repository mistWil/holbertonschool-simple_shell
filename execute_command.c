#include "shell.h"

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
