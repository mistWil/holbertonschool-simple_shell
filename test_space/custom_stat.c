#include "shell.h"

/**
 * custom_stat - return structure stat considering a path
 * @path: path (char*)
 * @buf: (struct stat*)
 *
 * Return: int
 */
int custom_stat(const char *path, struct stat *buf)
{
	return (stat(path, buf));
}
