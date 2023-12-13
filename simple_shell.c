#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#define MAX_BUFFER_SIZE 1024
/**
 * main - simple_shell
 *
 * Return: int
 */
int main(void)
{
	char *command = NULL;
	size_t bufferSize = 0;

	while (1)
	{
		printf("$ ");

		ssize_t nread = getline(&command, &bufferSize, stdin);

		if (nread == -1)
		{
			printf("\n");
			free(command);
			break;
		}

		command[strcspn(command, "\n")] = '\0';
		pid_t pid = fork();

		if (pid == -1)
		{
			perror("fork");
			free(command);
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			char *args[] = {command, NULL};

			execve(command, args, NULL);
			perror("execve");
			free(command);
			exit(EXIT_FAILURE);
		}
		else
		{
			wait(NULL);
		}
	}
	return (0);
}
