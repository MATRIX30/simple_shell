#include "main.h"

int comma_handler(char *lineptr);
/**
* comma_handler - function to handle command with comma's
* @lineptr: command string
* Return: 1 if string was comma seperated
*/
int comma_handler(char *lineptr)
{
	char *cma_sep = NULL;
	char *lineptr_cpy = NULL;
	int count = 0;
	char **cmd_table = NULL;
	int j = 0;
	char **cmds = NULL;
	char *del = ";";


	lineptr_cpy = strdup(lineptr);
	cma_sep = strtok(lineptr_cpy, del);
	while (cma_sep != NULL)
	{
		printf("%d\n", count);
		count++;
		cma_sep = strtok(NULL, del);
	}

	printf("%d\n",count);
	free(lineptr_cpy);
	if (count > 2)
	{
		cmds = malloc(sizeof(char *) * (count + 1));
		lineptr_cpy = strdup(lineptr);
		cmds[j]  = strtok(lineptr_cpy, del);
		while (cmds[j] != NULL)
		{
			printf("---%s\n", cmds[j]);
			cmds[j] = strtok(NULL, del);
			j++;
		}
		cmds[j] = NULL;
		j = 0;
		while (cmds[j] != NULL)
		{
			printf("%s\n", cmds[j]);
			if (built_ins(cmds[j]) == 1)
			{
				errno = 0;
			}
			else
			{
				cmd_table = split_string(cmds[j], del);
				if (executor(cmd_table) == 1)
				{
					errno = 0;;
				}
				else
				{
					perror("error");
					errno = ENOENT;
				}
			}
			j++;
		}
	}
	return (0);
}
