#include "main.h"

/**
* executor - function to execute commands
* @command_table: array of commands
* Return: 0 on success and 1 otherwise
*/
int executor(char **command_table);
int executor(char **command_table)
{

	pid_t __attribute__((unused))parent_id, child_id;
	int wstatus;
       /*	int child_exit_code = 0;*/
	int s = 0;

	char *env[] = {NULL};

	parent_id = getpid();

	/*printf("%d\n",parent_id);*/
	/* creating child process */
	child_id = fork();

	if (child_id == -1)
	{
		/* incase of creation failure */
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (child_id == 0)
	{
		/*specify tast to perfom in child here */
		if (execve(command_table[0], command_table, env) == -1)
		{
			/* in case of failure */
			/*perror(command_table[0]);*/
			/*exit(0);*/
			s = errno;
			exit(errno);
		}

	}
	else

	{
		/* specify task to perform in parent */
		wait(&wstatus);
	/*	if (WIFEXITED(wstatus))
		{
			child_exit_code = WEXITSTATUS(wstatus);
			if (child_exit_code == 0)
			{
				printf("Success with %d\n", child_exit_code);
			}
			else
			{
				printf("Failure with %d\n", child_exit_code);
			}
		}*/
	}

	exit(s);
}
