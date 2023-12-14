#define _GNU_SOURCE

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>


/**
 * main - program that mimic a super simple shell)
 *
 * Return: 0
 */

int main(void)
{
	int status;
	char *path = NULL;
	char *args[] = {NULL};
	size_t pathSize = 0;
	ssize_t bytesRead;
	pid_t childPid;

	while (1)
	{
		printf("$ ");
		bytesRead = getline(&path, &pathSize, stdin);
		if (bytesRead == -1)
		{
			perror("Error");
			if (feof(stdin))
				break;
		}
		path[bytesRead - 1] = '\0';

		childPid = fork();
		if (childPid == -1)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}
		else if (childPid == 0)
		{
			if (execve(path, args, NULL) == -1)
			{
				perror("Error");
				free(path);
				exit(EXIT_FAILURE);
			}
		}
		else
			wait(&status);
	}
	free(path);
	return (0);
}
