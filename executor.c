#include "main.h"

/**
* executor - function to execute commands
* @command_table: array of commands
* Return: 1 on success and 0 otherwise
*/

int executor(char **command_table)
{
	extern int errno;
	pid_t parent_id, child_id;
	int wstatus;

	char *env[] = {NULL};

	parent_id = getpid();

	printf("%d\n",parent_id);
	/* creating child process */
	child_id = fork();

	if (child_id == -1)
	{
		/* incase of creation failure */
		perror("fork");
		exit(errno);
	}

	if (child_id == 0)
	{
		/*specify tast to perfom in child here */
		if (execve(command_table[0], command_table, env) == -1)
		{
			/* in case of failure */
			exit(errno);
		}

	}
	else
	{
		/* specify task to perform in parent */
		wait(&wstatus);
	}

	return (0);
}
