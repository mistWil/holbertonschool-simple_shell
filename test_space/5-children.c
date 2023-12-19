#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - fork and wait and execve example
 *
 * Return: 0
 */

int main(void)
{
	char *args[] = {"/bin/ls", "-l", "/tmp", NULL};
	int i = 0, status;
	pid_t my_child;

	while (i < 5)
	{
		my_child = fork();
		if (my_child == -1)
			return (-1);
		if (my_child == 0)
		{
			if (execve(args[0], args, NULL) == 0)
				perror("Error");
		}
		wait(&status);
		i++;
	}
	return (0);
}
