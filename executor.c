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
	int exit_status = 0;

	char *env[] = {NULL};
	static int statu;


	statu = 0;
	parent_id = getpid();

	/*printf("%d\n",parent_id);*/
	/* creating child process */
	child_id = fork();

	if (child_id == -1)
	{
		/* incase of creation failure */
		perror("fork");
		free_array(command_table);
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
			statu = 2;
			errno = statu;
			free_array(command_table);
			exit(statu);
		}
		statu = 0;

	}
	else

	{
		/* specify task to perform in parent */
		wait(&wstatus);
		if (WIFEXITED(wstatus))
		{
			exit_status = WEXITSTATUS(wstatus);
			statu = 2;
			errno = exit_status;
			/*exit_status = statu;*/
			errno = 2;
		}
	}
	/*free_array(command_table);*/

	return (statu);
}
