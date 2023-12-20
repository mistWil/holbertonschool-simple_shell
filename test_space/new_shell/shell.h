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
char **split_line(char *line);
int execute_command(char **args);
char *get_and_copy_path(char *path);
char *_which(char *filename);
char *_getenv(const char *name);

#endif /* SHELL_H */
