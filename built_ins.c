#include "main.h"
/**
* built_ins - function to execute build-in shell commands
* @cmd: character pointer to commands entered
* Return: 1 on success and o otherwise
*/

int built_ins(char *cmd)
{
	extern int errno;
	extern char **environ;
	int status;
	char *del = " \n";
	char *cmd_cpy = NULL;
	char *token = NULL;

	cmd_cpy = strdup(cmd);
	token = strtok(cmd_cpy, del);

	if (token == NULL)
	{
		return (0);
	}
	if (strcmp(token, "exit") == 0)
	{
		token = strtok(NULL, del);
		if (token != NULL)
		{
			status = atoi(token);
			/* implement logic to test token for the folowng*/
			/* - when token cotains no digits  ie string*/
			/* - when token is negative */
			exit(status);
		}
		exit(0);
	}
	else if (strcmp(token, "env") == 0)
	{
		while (*environ)
		{
			_print(*environ);
			_putchar('\n');
			environ++;
		}
		return (1);
	}
	return (0);
}
