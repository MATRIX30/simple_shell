#ifndef SHELL_HEADER
#define SHELL_HEADER
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
char **split_string(char *str, char *del);
int handle_path(char **command_table);
int file_handler(char *filename);
int executor(char **command_table);
/* implemented in util.c file */
int _putchar(char c);
int _print(char *str);
void free_array(char **arr);
char *_getenv(const char *name);
int _strlen(const char *str);
#define BUFFER_SIZE 1024
#endif
