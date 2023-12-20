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
	int position = 0;
	char **tokens;
	char *token = NULL;

	tokens = malloc(strlen(line) * sizeof(char *));
	if (tokens == NULL)
	{
		return (NULL);
	}
	token = strtok(line, " \t\r\n\a");
	if (token == NULL)
	{
		free(tokens);
		return (NULL);
	}
	while (token != NULL)
	{
		tokens[position] = token;
		position++;

		if (position >= MAX_INPUT_SIZE)
		{
			perror("command too long");
			free(token);
			free(tokens);
			exit(EXIT_FAILURE);
		}
		token = strtok(NULL, " \t\r\n\a");
	}
	tokens[position] = NULL;
	return (tokens);
}
