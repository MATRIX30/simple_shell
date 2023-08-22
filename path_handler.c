#include "main.h"

int handle_path(char **command_table);
/**
* handle_path - this function identifies the path where command is
* and exeutes command from that path
* @command_table: command table
* Return: 1 if it was successful 0 otherwise
*/
int handle_path(char **command_table)
{
	const char *paths = _getenv("PATH");
	char *dir = NULL;
	char *paths_cpy = NULL;

	char *del = ":";
	/* store current working directory*/
	size_t dir_size = 0;
	char *cur_dir = NULL;
	/*char *new_dir = NULL;*/
	struct stat s;
	char *new_cmd;

	cur_dir = getcwd(cur_dir, dir_size);
	/*printf("%s\n",paths);*/


	(void)command_table;

	if (paths == NULL)
	{
		/*free(cur_dir);*/
		return (0);
	}
	/*printf("%s\n",cur_dir);*/
	paths_cpy = strdup(paths);
	if (paths != NULL)
	{
		/*printf("%s\n",paths);*/
		dir = strtok(paths_cpy, del);
		while (dir != NULL)
		{
			/*printf("%s\n",dir);*/
			chdir(dir);
			/* when in that directory check for presene of executable*/
			if (stat(command_table[0], &s) == 0)
			{
				/* if the executable is found */
				/*printf("Found at %s\n",dir);*/
				/* check if it can be accessed */
				/*executing command */
				new_cmd = _strcat(dir, "/");
				new_cmd = _strcat(new_cmd, command_table[0]);
				/*printf("%s\n",new_cmd);*/
				chdir(cur_dir);
				command_table[0] = new_cmd;
				/*if (execve(command_table[0], command_table, NULL)== -1)*/
				if (executor(command_table) != 1)
				{
					perror("execution");
					free(cur_dir);
					free(paths_cpy);
					return (0);
				}
				
				free(cur_dir);
				free(paths_cpy);
				
				return (1);
			}

			/*new_dir = getcwd(new_dir, dir_size);*/
			/*printf("cur dir --> %s\n",new_dir);*/
			dir = strtok(NULL, del);
		}
	} 
	chdir(cur_dir);
	free(paths_cpy);
	/*free(cur_dir);*/
	/* change to the original directory before exiting */
	return (0);
}

/*
int main()
{
	char *command_table[] = {"ls","-la","/home/cyanide/workspace/alx/simple_shell",NULL}; 
	handle_path(command_table);
	return (0);
}
*/
