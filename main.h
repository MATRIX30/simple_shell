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
#include <signal.h>
#include <ctype.h>
extern char **environ;
extern int errno;
char **split_string(char *str, char *del);
int handle_path(char **command_table);
int file_handler(char *filename);
int executor(char **command_table);

/* print routine defined in print.c */
int _putchar(char c);
int _print(char *str);
int _putcharerr(char c);
int _printerr(char *str);

/* implemented in util.c file */
void free_array(char **arr);
char *_getenv(const char *name);
char *_getenv1(const char *name);

/* builtin functions */
int built_ins(char *cmd);
int _atoi(char *s);
char *_strtok(char *str, const char *del);
/* signal handling functions */
void signal_handler(int sig);

/* string methods */
char *_strcat(char *dest, char *src);
int _strlen(const char *str);
char *_strcpy(char *dest, char *src);
/* Advanced features */
int comma_handler(char *lineptr);
#define BUFFER_SIZE 1024
#endif
