#include "shell.h"

/**
* get_command - gets input from the user
* Return: read_input on succss
**/

char *get_command()
{
	char *read_input = NULL;
	size_t n = 0;
	size_t lenght;

	printf("shell$");

	if (getline(&read_input, &n, stdin) == -1)
	{
		printf("\n");
		free(read_input);
		exit(EXIT_SUCCESS);
	}

	lenght = strlen(read_input);

	if (lenght > 0 && read_input[lenght - 1] == '\n')
	{
		read_input[lenght - 1] = '\0';
	};

	return (read_input);
}
