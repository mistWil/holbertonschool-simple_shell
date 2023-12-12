#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * main - split a string
 * @ac: number of command line arguments
 * @av: arguments
 *
 * Return: 0
 */

int main(void)
{
	char phrase[] = "Hello, world! This is a simple example.";
	const char *delim = " ";
	char *copieToken = NULL;

	/* Utilisation de strtok pour obtenir le premier token*/
	char *token = strtok(phrase, delim);

	/* Utilisation de strtok pour obtenir les tokens suivants*/
	while (token != NULL)
	{
		/* Alloue de la mémoire pour le token*/
		copieToken = strdup(token);

		/* Utilisation de la copie du token*/
		printf("$ : %s\n", copieToken);

		/* Libère la mémoire allouée pour la copie du token*/
		free(copieToken);

		/**
		 * strtok est appelé avec NULL pour continuer
		 * à partir du dernier point d'arrêt
		 */
		token = strtok(NULL, delim);
	}

	return (0);
}
