#include "shell.h"

/**
 * split_line - split line corresponding
 * to the user input
 * @line: char*
 *
 * Return: char (tokens)
 */

char **split_line(char *line)
{
	int bufsize = MAX_INPUT_SIZE;
	int position = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (tokens == NULL)
	{
		perror("allocation error");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, " \t\r\n\a");
	while (token != NULL)
	{
		tokens[position] = token;
		position++;

		if (position >= bufsize)
		{
			perror("command too long");
			free(token);
			free(tokens);
			exit(EXIT_FAILURE);
		}

		token = strtok(NULL, " \t\r\n\a");
	}
	free(token);
	tokens[position] = NULL;
	return (tokens);
}
