#include "shell.h"

/**
* main - reads user input and executes command
*
* Return: val on success
**/

int shell_loop(void)
{
	char *input;
	char *command;
	char *args[MAX_ARGS];
	int val = EXIT_SUCCESS;
	int infinite = 1;

	while (infinite)
	{
		input = get_command();

	if (strcmp(input, "exit") == 0)
	{
		free(input);
		break;
	}

	parse_cmd(input, &command, args);

	if (command != NULL)
	{
		val = exec_cmd(command, args);
	}

		free(input);
	}
	return (val);
}

/**
* exec_cmd - this function executes commands
* @command: pointer to a char
* @args: array of pointer to a string
* Return: Always 0 on success
**/

int exec_cmd(char *command, char **args)
{
	pid_t pid;
	int form;

	pid = fork();

	if (pid == -1)
	{
		perror("unsuccessful");
		return (EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execvp(command, args) == -1)
	{
		perror("unsuccesful");
		exit(EXIT_FAILURE);
	}
	}
	else
	{

	waitpid(pid, &form, 0);
	}

	return (0);
}

