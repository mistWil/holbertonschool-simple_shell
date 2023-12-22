#include "shell.h"

/**
 * free_args - free the table of arguments
 * @args: table of arguments
 */

void free_args(char **args)
{
	int i = 0;

	if (args == NULL)
		return;
	for (i = 0; args[i] != NULL; i++)
	{
		free(args[i]);
	}
	free(args);
}
