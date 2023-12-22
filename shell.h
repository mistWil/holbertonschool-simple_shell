#ifndef NEW_SHELL_H
#define NEW_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_INPUT_SIZE 1024

extern char **environ;

int main(void);
int execute_command(char **args);
char **split_line(char *line);
void free_args(char **args);
char *get_path(char *command);
char *_getenv(const char *name);

#endif
