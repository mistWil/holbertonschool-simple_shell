#include "shell.h"

/**
 * file_exists - check if the file exist in the system
 * @filename : const char*
 *
 * Return: 0 if success
 */
int file_exists(const char *filename)
{
	struct stat st;

	return (custom_stat(filename, &st) == 0);
}
