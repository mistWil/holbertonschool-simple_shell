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
	char *cmd_path = NULL;
	pid_t child_pid;
	int status;

	if (access(args[0], X_OK) == 0)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}
		if (child_pid == 0)
		{
			cmd_path = _which(args[0]);

			if (execve(cmd_path, args, environ) == -1)
			{
				fprintf(stderr, "%s: No such file or directory\n", cmd_path);
				free(cmd_path);
				exit(EXIT_FAILURE);
			}
		}
		wait(&status);
	}
	free(cmd_path);
	return (status);
}
