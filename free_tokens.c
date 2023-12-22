#include "shell.h"

/**
 * free_tokens - loops to free tokens
 * @tokens: array of string
 * @position: the position in the array
 *
 * Return: void
 */

void free_tokens(char **tokens, int position)
{
	int i = 0;

	for (i = 0; i < position; i++)
	{
		free(tokens[i]);
	}
	free(tokens);
}
