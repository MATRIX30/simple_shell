#include "main.h"
#define BUF_SIZE 1024
int file_handler(char *filename);
/**
* file_handler - function to read and execute commands in files
* @filename: array of file names
* Return: 1 on success and 0 on failure
*/
int file_handler(char *filename)
{
	char *prog_name = _getenv("_");
	ssize_t fd;
	ssize_t read_size;
	char *buffer = NULL;
	char **cmd_table = NULL;
	char *del = "\n";

	/* section for counting */
	int count = 0;
	char *buff_cpy = NULL;
	char *token = NULL;
	char **cmd_list = NULL;
	int i = 0;

	buffer = malloc(sizeof(char) * BUF_SIZE);
	if (filename == NULL)
	{
		return (0);
	}
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		_printerr(prog_name);
		_printerr(": 0: cannot open ");
		_printerr(filename);
		_printerr(": No such file\n");
		free(buffer);
		/*free(prog_name);*/
		return (0);
	}

	read_size = read(fd, buffer, BUF_SIZE);
	if (read_size == -1)
	{
		return (0);
	}
	if (buffer == NULL)
		return (0);
	/* counting of number of commands*/
	buff_cpy = strdup(buffer);

	token = strtok(buff_cpy, del);
	while (token)
	{
		count++;
		token = strtok(NULL, del);
	}
	free(buff_cpy);
	/* create a dynamic array to hold command strings */
	cmd_list = malloc(sizeof(char *) * (count + 1));

	buff_cpy = strdup(buffer);
	cmd_list[i] = strtok(buff_cpy, del);

	while (cmd_list[i] != NULL)
	{
		i++;
		cmd_list[i] = strtok(NULL, del);
	}
	while (*cmd_list)
	{
		cmd_table = split_string(*cmd_list, " \n");
		executor(cmd_table);
		cmd_list++;
	}
	free(buff_cpy);
	/*free_array(cmd_list);*/
	free(buffer);

	close(fd);
	return (1);
}
