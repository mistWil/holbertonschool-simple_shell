#include "shell.h"

/**
 * custom_strdup - custom to return a copy
 * @str: (char*)
 *
 * Return: char (copy)
 */
char *custom_strdup(const char *str)
{
	size_t len = strlen(str) + 1;
	char *copy = malloc(len);

	if (copy)
	{
		strcpy(copy, str);
	}
	return (copy);
}
