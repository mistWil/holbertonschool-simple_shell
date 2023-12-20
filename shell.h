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
char *read_line(void);
int execute_command(char **args);
char **split_line(char *line);

#endif
