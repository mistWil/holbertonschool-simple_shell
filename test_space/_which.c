#include "main.h"

/**
 * get_and_copy_path - get and copy the location of an executable in the PATH.
 * @path: path to copy.
 *
 * Return: A copy of the path of the executable,
 *         or NULL if not found.
 */

char *get_and_copy_path(char *path)
{
	char *pathCopy;

	path = getenv("PATH");
	if (path == NULL)
	{
		fprintf(stderr, "Error: the PATH environment variable is not set.\n");
		return (NULL);
	}
	/* Copy the PATH variable to avoid modifying it directly*/
	pathCopy = strdup(path);
	if (pathCopy == NULL)
	{
		perror("Error duplicating the path");
		free(pathCopy);
		return (NULL);
	}
	return (pathCopy);
}

/**
 * _which - create the full path of an executable from the PATH if found
 * @filename: The name of the executable to search for.
 *
 * Return: A dynamically allocated string with the full path of the executable,
 *         or NULL if not found.
 */

char *_which(char *filename)
{
	char *result = NULL;
	char *pathCopy = get_and_copy_path("PATH");
	char *token;
	char *fullPath;
	size_t pathLen;

	/* Go through and tokenize the directories in the PATH copy*/
	token = strtok(pathCopy, ":");
	while (token != NULL)
	{
		/*Building the full path*/
		pathLen = strlen(token) + strlen(filename) + 2;
		fullPath = malloc(pathLen);
		if (fullPath == NULL)
		{
			perror("Error allocating memory");
			free(pathCopy);
			return (NULL);
		}
		snprintf(fullPath, pathLen, "%s/%s", token, filename);
		/* Check if file exists at this location*/
		if (access(fullPath, X_OK) == 0)
		{
			/* File found, assign the restul and break out of the loop*/
			result = fullPath;
			free(pathCopy);
			return (result);
		}
		/* Free the memory allocated for the full path*/
		free(fullPath);
		/* Move to the next directory in the PATH*/
		token = strtok(NULL, ":");
	}
	/*Free the memory allocated for the PATH copy*/
	free(pathCopy);
	return (result);
}

/**
 * main - write a filename full path
 *
 * Return: 0 on success, 1 on failure.
 */

int main(int ac, char *filename[])
{
	char *location = _which(filename[1]);

	if (ac != 2)
	{
		fprintf(stderr, "Usage: %s\n", filename[0]);
		return (1);
	}

	if (location != NULL)
	{
		printf("The location of '%s' is: %s\n", filename[1], location);
		free(location);
		return (1);
	}
	printf("'%s' was not found in the PATH.\n", filename[1]);

	return (0);
}
