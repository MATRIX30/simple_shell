#include "main.h"

/**
 * main - entry point
 * argc: number of command line arguments
 * @argv: array of strings containg command line arguments
 * @env: array of strings containing environment variables
 *
 * Return: always 0
 */
int main(int argc, char **argv, char **env)
{
info_t info;

/* Initialize info structure and set environment variables */
info.argv = argv;
info.env = env;
info.status = status;
info.err_num = 0;

char *line = NULL;
size_t len = 0;

while (1) {

	/* print a shell prompt */
_print("$ ");

/* read a line of input from the user */
if (getline(&line, &len, stdin) == -1) {
perror("getline");
exit(EXIT_FAILURE);
}

/* Remove newline character from the input */

line[strcspn(line, "\n")] = '\0';

/* handle built in commands */



