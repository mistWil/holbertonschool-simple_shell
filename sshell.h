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

int execute_command(char **args);
char *read_line(void);
char **split_line(char *line);
char *_which(char *command);
int custom_stat(const char *path, struct stat *buf);
int is_interactive(void);
int file_exists(const char *filename);
char *custom_strdup(const char *str);

#endif /* SHELL_H */

