#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>
#include <string.h>
#include <fcntl.h>
#include <dirent.h>

/* Function Prototypes */
int main(int argc, char *envp[]);
char **parse_input(char *input);
int execute_command(char **args, char *envp[]);
int execute_builtin(char **args, char *envp[]);
char *get_path(char *command);
void free_args(char **args);

#endif /* SHELL_H */

