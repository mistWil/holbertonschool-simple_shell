#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024
/**
 * main - start shell function
 *
 * Return: int
 */

int main()
{
	char *command = NULL;
	size_t bufferSize = 0;

	while (1) {
		/*Afficher l'invite*/
		printf("$ ");

		/*Lire la commande de l'utilisateur avec getline*/
		ssize_t nread = getline(&command, &bufferSize, stdin);

		if (nread == -1)
		{
			/*Gérer la fin de fichier (Ctrl+D)*/
			printf("\n");
			free(command);
			break;
		}

		/*Supprimer le caractère de nouvelle ligne à la fin de la commande*/
		command[strcspn(command, "\n")] = '\0';

		/*Créer un processus fils*/
		pid_t pid = fork();

		if (pid == -1)
		{
			/*Gérer les erreurs de fork*/
			perror("fork");
			free(command);
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			/*Code du processus fils*/
			/*Exécuter la commande avec execve*/
			char *args[] = {command, NULL};
			execve(command, args, NULL);

			/*Si execve échoue, afficher un message d'erreur*/
			perror("execve");
			free(command);
			exit(EXIT_FAILURE);
		}
		else
		{
			/*Code du processus parent*/
			/*Attendre que le processus fils se termine*/
			wait(NULL);
		}
	}

	return (0);
}
