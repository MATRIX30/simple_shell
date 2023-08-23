#include "main.h"
#include <stdio.h>

int main(int ac, char **av, char __attribute__((unused)) **env);
void signal_handler(int __attribute__((unused)) sig);
/**
* main - main entry point to our shell program
* @ac: argument count
* @av: array of  string argumements passed to the shell
* @env: environmental variables
* Return: 0 on success 1 otherwise
*/
int main(int  ac, char **av, char __attribute__((unused)) **env)
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
	struct stat s;
	int a = 0;

	/*char *comment_free_lineptr = NULL;*/
	/*char *dirs = _getenv("PATH");*/

	/**
	* 1) Lexical Analyzer: get commands from both interactive
	*    and file based mode and generate command Table
	*/

	/**
	* - Interactive shell design
	*/


	/* registration of signals */
	signal(SIGINT, signal_handler);

	/** handling entry of command from file **/
	if (ac > 1)
	{
		/* file_handler code here*/
		if (file_handler(av[1]) != 1)
		{
			exit(2);
		}
		exit(EXIT_SUCCESS);
	}

	/* register and handle signals here */
	/*signal(SIGINT, signal_handler);*/

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
			/*free(lineptr);*/
			exit(0);
		}

		/**
		* Handling comma seperated commands
		*/
		/*if (comma_handler(lineptr) == 1)*/
			/*continue;*/
		/**
		* Handle Buit-ins here
		* built_ins - function to execute build-in commands
		* Takes typed commands throught lineptr
		* Returns: 1 if successful ie command entered was a
		* built-in command and 0 otherwise
		*/

		if (built_ins(lineptr) == 1)
		{
			/*free(lineptr);*/
			continue;
		}

		/**
		* Handling comments # by spliting commands based on #
		* and taking just the first part of the string
		*/

		/**
		* comment_free_lineptr = strdup(lineptr);
		* printf("%s\n",comment_free_lineptr);
		* comment_free_lineptr = strtok(comment_free_lineptr, "#");
		*/

		/*lineptr = strtok(lineptr, "#");*/
		
		/**
		* Generate commands table from lineptr
		* with the help of strtok tokenizing function
		*/
		command_table = split_string(lineptr, del);
		/*free(lineptr);*/
		/* handling a Null command table */
		if (command_table == NULL)
		{
			free(lineptr);
			free_array(command_table);
			continue;
		}

		/**
		* 2) executor engine: This component makes use of
		*    execve system call to execute task on the kernel
		*    making use of fork to create new processes to
		*    execute each command
		*/

		/*verify if executable is in current working directory*/
		if (stat(command_table[0], &s) == 0)
		{
			free(lineptr);
			a = executor(command_table);
			/*printf("This is that code %d\n",a);*/
			continue;
		
		}
		a = handle_path(command_table);
		if (a == 0)
		{
			free(lineptr);
			/* look for executable in paths and execute */
			continue;
		}
		else
		{
		     /*	errno = ENOENT;*/
		     _printerr(av[0]);
		     _printerr(": 1: ");
		     _printerr(command_table[0]);
		     _printerr(": not found\n");
		     /*errno = 127;*/

		     /*	perror(command_table[0]);*/
		     free(lineptr);
		     continue;
		}

	}
	/*exit(errno);*/
	free_array(command_table);
	free(lineptr);
	return(errno);
}

/**
* signal_handler - function to handle signals sent to the prompt
* @sig: integer value send by signal
*/

void signal_handler(int __attribute__((unused)) sig)
{
	_print("\n($) ");
}
