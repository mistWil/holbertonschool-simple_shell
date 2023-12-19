#include "shell.h"

/**
 * execute_command - function which execute command
 * find in system
 * @args: pointer**
 *
 * Return: 1 if success
 */
int execute_command(char **args)
{
	pid_t pid, wpid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		char *cmd_path = which(args[0]);

		if (cmd_path != NULL)
		{
			if (execve(cmd_path, args, NULL) == -1)
			{
				perror("shell");
			}
			free(cmd_path);
		}
		else
		{
			perror("command not found");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("shell");
	}
	else
	{
		do
			wpid = waitpid(pid, &status, WUNTRACED);
		while
			(!WIFEXITED(status) && !WIFSIGNALED(status));
		if (wpid == -1)
		{
			perror("waitpid");
			exit(EXIT_FAILURE);
		}
	}
	return (1);
}
