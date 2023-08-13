#include "main.h"
/**
* main - main entry point to our shell program
* @ac: argument count
* @av: array of  string argumements passed to the shell
* Return: 0 on success 1 otherwise
*/
int main(int __attribute__((unused)) ac, char __attribute__((unused)) **av);
int main(int __attribute__((unused)) ac, char __attribute__((unused)) **av)
{
	/**
	* Component based design of Shell
	* Our Shell is divided into 3 core components
	* 1) Lexical analyzer: This component will take in text commands
	*    Both in interactive and Batch/File Mode and generate a
	*    command table that needs to be executerd
	* 2) Executor: this components is responsible for running all
	*    the commands in the command table
	* 3) shell sub-sytem: this phase constitute of implementing
	*    extra functionalities through the use of built-ins
	*/

	/**
	 * NB: Requirements :
	 *  - shell should meet specifications of ALx Shell project
	 *  - Give correct error messages like sh(/bin/sh) unless other
	 *    wise stated
	 *  - should be no memory leakage(ensure this with valgrind)
	 *  - Beautiful code sytle that meets Betty Specifications
	 *    betty *.[ch] should all pass
	 *  - Compilation flag: gcc -Wall -Werror -Wextra -pedantic
	 *    -std=gnu89 *.c -o hsh
	 */
	char *lineptr = NULL;
	char **command_table;
	char *del = " \n";
	size_t n = 0;
	ssize_t char_read;
	pid_t child;
	/*pid_t father;*/
	int status;

	/**
	* 1) Lexical Analyzer: get commands from both interactive
	*    and file based mode and generate command Table
	*/

	/**
	* - Interactive shell design
	*/

	/* infinite loop to run shell */
	while (1)
	{
		printf("($) ");
		char_read = getline(&lineptr, &n, stdin);
		/* on getline failure return -1 */
		if (char_read == -1)
		{
			/* test if EOF(ctrl + D) has been encountered */
			/**
			*if (feof(stdin))
			* {
			*	printf("\n");
			*	_exit(0);
			*
			* }
			*/
			printf("\n");
			_exit(1);
		}

		/**
		* Generate commands table from lineptr
		* with the help of strtok tokenizing function
		*/
		command_table = split_string(lineptr, del);

		/**
		* 2) executor engine: This component makes use of
		*    execve system call to execute task on the kernel
		*    making use of fork to create new processes to
		*    execute each command
		*/

		/*creat a seperate child process*/
		child = fork();
		if (child == -1)
		{
			/* in case of failure in creating child process*/
			perror("fork");
			exit(EXIT_FAILURE);
		}
		if (child == 0)
		{
			/**
			 *  task to perform while in child process
			 *  printf("child process started\n");
			 */
			if (execve(command_table[0], command_table, NULL) == -1)
			{
				perror("./shell");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			/**
			* task to perform while in parent process
			* - wait for child process to finish continue
			*   infinte looping
			*/
			printf("waiting for child\n");
			wait(&status);
		}

	}
	free(lineptr);
	return (0);
}
