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

	char *path;
	char *cwd = NULL;

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
	if (strcmp(token, "cd") == 0)
	{
		path = strtok(NULL, del);
		if (path == NULL)
		{
			return (chdir(getenv("HOME")) + 1);
		}
		else if (strcmp(path, "-") == 0)
		{
			path = getenv("OLDPWD");
			if (path == NULL)
			{
				_printerr("path null");
			}
			else
			{
				cwd = getcwd(cwd, 1024);
				_print(path);
				setenv("OLDPWD", cwd, 1);
				setenv("PWD", path, 1);
				return (chdir(path) + 1);
			}
		}
		else
		{
			return (chdir(path) + 1);
		}
	}
	return (statu);
}
