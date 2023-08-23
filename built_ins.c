#include "main.h"
/**
* built_ins - function to execute build-in shell commands
* @cmd: character pointer to commands entered
* Return: 1 on success and o otherwise
*/
int built_ins(char *cmd);
int built_ins(char *cmd)
{
	/*extern char **environ;*/
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
			status = _atoi(token);
			/* implement logic to test token for the folowng*/
			/* - when token cotains no digits  ie string*/
			/* - when token is negative */
			free(cmd_cpy);
			free(cmd);
			exit(status);
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
	free(cmd_cpy);
	return (statu);
}
