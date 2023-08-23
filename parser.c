#include "shell.h"


/**
* parse_cmd - This function parses commands
* @input: pointer to the char representing the input string
* @command: used to store the address of the command string
* @args: used to store the adrress of arguments
* Return - Always 0 on success
**/

void parse_cmd(char *input, char **command, char **args)
{

	int i = 0;

	const char *delim = " ,:/*";
	char *token = strtok(input, delim);

	if (!token)
	{
		*command = NULL;
		return;
	}

	*command = token;

	for (i = 0; token != NULL; i++)
	{
		args[i] = token;
		token = strtok(NULL, delim);
	}

}

