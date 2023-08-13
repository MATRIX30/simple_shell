#include "main.h"
/**
* split_string - function splits a string
* @str: string to be splited
* @del: delimiter to use in spliting
* Return: an array of splitted strings
*/
char **split_string(char *str, char *del);
char **split_string(char *str, char *del)
{
	/**
	* char *str must be an array of characters if its a string
	* literal it will lead to a segmentation fault as strtok
	* modifies str by inserting \0 character when ever it finds
	* delimiters
	*/

	/**
	*  make a copy of str by multiplying what ever its pointing to
	*  x the string length
	*/
	char *str_cpy = malloc(sizeof(*str) * strlen(str));
	/**
	* str_count is used to get the number of tokens we can
	* get from the string str and will be destroyed due to the
	* modifying effect of strtok
	*/
	char *str_count = malloc(sizeof(*str) * strlen(str));
	static char **buffer;
	size_t token_count;
	char *token = NULL;
	size_t j = 0;

	strcpy(str_cpy, str);
	strcpy(str_count, str);
	/*printf("%s\n",str_cpy);*/
	if (str == NULL || del == NULL)
	{
		printf("string or del shouldn't be NULL\n");
		exit(0);
	}

	token = strtok(str_count, del);
	for (token_count = 0; token != NULL; token_count++)
	{
		token = strtok(NULL, del);
	}
	free(str_count);
	/*printf("%ld\n",token_count);*/
	buffer = malloc(sizeof(*buffer) * token_count);
	token = strtok(str_cpy, del);
	buffer[j] = strdup(token);
	if (buffer[j] == NULL)
	{
		printf("Error tokenizing");
		exit(0);
	}
	for (j = 1; j < token_count; j++)
	{
		token = strtok(NULL, del);
		buffer[j] = malloc(sizeof(char) * strlen(token));
		strcpy(buffer[j], token);
	}
	buffer[j] = NULL;
	return (buffer);
}
