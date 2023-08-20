#include "main.h"
#include <stdio.h>
/**
* handle_path - this function identifies the path where command is
* and exeutes command from that path
* @command_table: command table
* Return: 1 if it was successful 0 otherwise
*/
int handle_path(char **command_table)
{
	/* flag_dir checks if dir has already been generated*/
	/* and prevent further generations on subsiquent calls*/
	static int flag_dir = 0;
	const char *paths = _getenv("PATH");
	char *dir = NULL;
	char *paths_cpy = NULL;

	char *del = ":";
	/* store current working directory*/
	size_t dir_size = 0;
	char *cur_dir = NULL;
	char *new_dir = NULL;
	struct stat s;
	char *new_cmd;
	cur_dir = getcwd(cur_dir, dir_size);
	/*printf("%s\n",paths);*/


	(void)command_table;

	/* we need to make a copy of dir cause strtok destroys*/
	/*if (flag_dir == 0)
	{
		paths = _getenv("PATH");
		flag_dir = 1;
	}*/
	printf("hello\n");
	paths_cpy = strdup(paths);
	printf("%p\n",(void *)&paths_cpy);
	printf("%p\n",(void *)&paths);
	printf("%d\n",flag_dir);
	
	if(paths == NULL)
	{
		printf("Path is NULL\n");
		paths =_getenv("PATH");
	}
	printf("%s\n",cur_dir);
	if (paths != NULL)
	{
		printf("%s\n",paths);
		dir = strtok(paths_cpy, del);
		while(dir != NULL)
		{
			/*printf("%s\n",dir);*/
			chdir(dir);
			/* when in that directory check for presene of executable*/
			if (stat(command_table[0], &s) == 0)
			{
				/* if the executable is found */
				printf("Found at %s\n",dir);
				/*executing command */
				new_cmd = strcat(dir,"/");
				new_cmd = strcat(new_cmd,command_table[0]);
				printf("%s\n",new_cmd);
				chdir(cur_dir);
				if (execve(new_cmd, command_table, NULL)== -1)
					printf("something went wrong");
				break;
			}

			new_dir = getcwd(new_dir, dir_size);
			dir = strtok(NULL, del);
			printf("cur dir --> %s\n",new_dir);
		}
	}
	chdir(cur_dir);
	free(paths_cpy);
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
