#define _GNU_SOURCE

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>


/**
 * main - program that mimic a super simple shell)
 * @ac: number of arguments
 * @commandPath: arguments
 * @env: environnemental variables
 *
 * Return: 0
 */

int main(int ac, char **commandPath, char **env)
{
	int status;
	size_t commandSize = 0;
	ssize_t bytesRead;
	pid_t childPid;

	(void)ac;
	(void)env;

	while (1)
	{
		printf("$ ");
		bytesRead = getline(commandPath, &commandSize, stdin);
		if (bytesRead == -1)
		{
			perror("Error");
			if (feof(stdin))
				break;
		}
		*commandPath[bytesRead - 1] = '\0';

		childPid = fork();
		if (childPid == -1)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}
		else if (childPid == 0)
		{
			for (int i = 0; i < (bytesRead - 2); i++)
				printf("%s", commandPath[i]);
			if (execve(commandPath[0], commandPath, environ) == -1)
			{
				perror("Error");
				free(*commandPath);
				exit(EXIT_FAILURE);
			}
		}
		else
			wait(&status);
	}
	free(*commandPath);
	return (0);
}
