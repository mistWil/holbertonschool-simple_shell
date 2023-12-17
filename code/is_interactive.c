#include "shell.h"

/**
 * is_interactive - testing if we are in interactive mode
 * @void: void
 *
 * Return: int 1 if interactive
 */
int is_interactive(void)
{
	return (isatty(STDIN_FILENO));
}
