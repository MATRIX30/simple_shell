#ifndef SHELL_HEADER
#define SHELL_HEADER
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
int _putchar(char c);
int _print(char *str);
char **split_string(char *str, char *del);
#define BUFFER_SIZE 1024
#endif
