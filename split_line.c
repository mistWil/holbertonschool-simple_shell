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

	tokens = malloc(strlen(line) * sizeof(char *) + 1);
	if (tokens == NULL)
	{
		return (NULL);
	}
	token = strtok(line, " \t");
	while (token != NULL)
	{
		if (strlen(token) > 0)
		{
			tokens[position] = strdup(token);
			if (tokens[position] == NULL)
			{
				perror("strdup failed");
				free_args(tokens);
				exit(EXIT_FAILURE);
			}
			position++;
		}
		token = strtok(NULL, " \t");
	}
	/*if (position == 0)
	{
		free(tokens);
		return (NULL);
	}*/
	tokens[position] = NULL;
	return (tokens);
}
