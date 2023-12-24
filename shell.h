#ifndef SHELL_H
#define SHELL_H

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
void execute_command(char *argv[], char *line);
void split_line(char *line);
char *get_path(char *command);
char *_getenv(const char *name);
int _printenv(void);

#endif
