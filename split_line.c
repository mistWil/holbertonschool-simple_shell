#include "shell.h"

/**
 * split_line - split line corresponding
 * to the user input
 * @line: char*
 *
 * Return: char (tokens)
 */
void split_line(char *line)
{
	int position = 0;
	char *tokens[1024] = {NULL};
	char *token = NULL;

	token = strtok(line, " \t");
	while (token != NULL)
	{
		if (strlen(token) > 0)
		{
			tokens[position] = token;
			position++;
		}
		token = strtok(NULL, " \t");
	}
	if (tokens[0] == NULL)
	{
		return;
	}
	if (strcmp(tokens[0], "exit") == 0 && tokens[1] == NULL)
	{
		free(tokens[0]);
		exit(0);
	}
	if (strcmp(tokens[0], "env") == 0)
	{
		_printenv();
		return;
	}
	token = strdup(tokens[0]);
	tokens[0] = get_path(token);
	if (tokens[0] != NULL)
	{
		free(token);
		execute_command(tokens, line);
		free(tokens[0]);
		return;
	}
	fprintf(stderr, "./hsh: 1: %s: not found\n", token);
	free(token);
	exit(127);
}
