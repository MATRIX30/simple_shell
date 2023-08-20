#include "main.h"
#include <stdio.h>
/**
* main - main entry point to our shell program
* @ac: argument count
* @av: array of  string argumements passed to the shell
* Return: 0 on success 1 otherwise
*/
int main(int ac, char **av, char **env);
int main(int  ac, char **av, char **env)
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

	extern int errno;
	char *lineptr = NULL;
	char **command_table;
	char *del = " \n";
	size_t n = 0;
	ssize_t char_read;
	pid_t child;
	/*pid_t father;*/
	int status;
	struct stat s;
	/*char *dirs = _getenv("PATH");*/

	/**
	* 1) Lexical Analyzer: get commands from both interactive
	*    and file based mode and generate command Table
	*/

	/**
	* - Interactive shell design
	*/

	/** handling entry of command from file **/
	if (ac > 1)
	{
		/* file_handler code here*/
		if(file_handler(av[1]) != 1)
		{
			/*_print("Usage: simple_shell [file name]\n");*/
			perror("./hsh");
		}
		exit(errno);
	}





	/* infinite loop to run shell */
	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
			_print("($) ");
		char_read = getline(&lineptr, &n, stdin);
		/* on getline failure return -1 */
		if (char_read == -1)
		{
			/* test if EOF(ctrl + D) has been encountered */
			if (isatty(STDIN_FILENO) == 1)
			{
				_putchar('\n');
			}
			free(lineptr);
			exit(0);
			/*exit(errno);*/
		}

		/**
		* Handle Buit-ins here
		* built_ins - function to execute build-in commands
		* Takes typed commands throught lineptr 
		* Returns: 1 if successful ie command entered was a 
		* built-in command and 0 otherwise
		*/

		if (built_ins(lineptr) == 1)
		{
			continue;
		}

		/**
		* Generate commands table from lineptr
		* with the help of strtok tokenizing function
		*/
	
		command_table = split_string(lineptr, del);
		
		/*free(lineptr);*/
	

		/* handling a Null command table */
		if (command_table == NULL)
		{
			continue;
		}

		/**
		* 2) executor engine: This component makes use of
		*    execve system call to execute task on the kernel
		*    making use of fork to create new processes to
		*    execute each command
		*/

		/** Handle paths here by verifying if command exist in paths then execute **/
		if (stat(command_table[0],&s) != 0)
		{
			_print("File Not found -- process paths\n");
			printf("*********%s\n", command_table[0]);
			/*handle_path(command_table);*/
			continue;
		}

		/*creat a seperate child process*/
		child = fork();
		if (child == -1)
		{
			/* in case of failure in creating child process*/
			perror("fork");
			exit(EXIT_FAILURE);
			/*exit(errno);*/
		}
		if (child == 0)
		{
			/**
			 *  task to perform while in child process
			 *  printf("child process started\n");
			 */
			if (execve(command_table[0], command_table, env) == -1)
			{
				
				perror("./shell");
				exit(EXIT_FAILURE);
				/*exit(errno);*/
			}
			/*free(lineptr);*/
			/*free_array(command_table);*/
		}
		else
		{
			/**
			* task to perform while in parent process
			* - wait for child process to finish continue
			*   infinte looping
			*/
			wait(&status);
		}
		/*free(lineptr);*/
		/*free_array(command_table);*/

	}
	return (0);
}
