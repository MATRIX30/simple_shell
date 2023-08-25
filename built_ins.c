#include "main.h"
/**
* built_ins - function to execute build-in shell commands
* @cmd: character pointer to commands entered
* Return: 1 on success and o otherwise
*/
int built_ins(char *cmd);
int built_ins(char *cmd)
{
	int status;
	char *del = " \n";
	char *cmd_cpy = NULL;
	char *token = NULL;

	char **en = NULL;
	static int statu;

	statu = 0;

	en = environ;
	cmd_cpy = strdup(cmd);
	token = strtok(cmd_cpy, del);



	if (*environ == NULL)
	{
		free(cmd_cpy);
		return (0);
	}
	if (token == NULL)
	{
		free(cmd_cpy);
		return (0);
	}
	if (strcmp(token, "exit") == 0)
	{
		token = strtok(NULL, del);
		if (token != NULL)
		{
			status = atoi(token);
			/* implement logic to test token for the folowng*/
			if (status == 0 || atoi(token) < 0)
			{
				_printerr("./hsh: 1: exit: Illegal number: ");
				_printerr(token);
				_printerr("\n");
				statu = 2;
				errno = 2;

				free(cmd_cpy);
				free(cmd);
				exit(statu);
			}
			/* - when token cotains no digits  ie string*/
			/* - when token is negative */
			free(cmd_cpy);
			free(cmd);
			exit(statu);
		}
		if (errno == 127)
		{
			statu = 2;
		}
		free(cmd);
		free(cmd_cpy);
		exit(statu);
	}
	else if (strcmp(token, "env") == 0)
	{
		while (*environ)
		{
			_print(*environ);
			_putchar('\n');
			environ++;
		}
		environ = en;
		free(cmd_cpy);
		return (1);
	}
	else if (strcmp(token, "cd") == 0)
	{
		token = strtok(NULL, del);

	}
	free(cmd_cpy);
	return (statu);
}
