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
	/*char *str_cpy = malloc(sizeof(*str) * strlen(str));*/
	char *str_cpy;
	/**
	* str_count is used to get the number of tokens we can
	* get from the string str and will be destroyed due to the
	* modifying effect of strtok
	*/
	/*char *str_count = malloc(sizeof(*str) * strlen(str));*/
	static char **buffer;
	size_t token_count;
	char *token = NULL;
	size_t j = 0;

	/*strcpy(str_cpy, str);*/
	/*strcpy(str_count, str);*/
	/*printf("%s\n",str_cpy);*/

	if (str == NULL || del == NULL)
	{
		_print("string or del shouldn't be NULL\n");
		exit(0);
	}

	str_cpy = strdup(str);
	if (str_cpy == NULL)
	{
		/*fail to copy */
		return (NULL);
	}
	/*token = strtok(str_count, del);*/
	token = strtok(str_cpy, del);
	for (token_count = 0; token != NULL; token_count++)
	{
		token = strtok(NULL, del);
	}
	/*free(str_count);*/
	free(str_cpy);
	buffer = malloc(sizeof(*buffer) * token_count);
	/* check for allocation failed */
	if (buffer == NULL)
		return (NULL);
	str_cpy = strdup(str);
	token = strtok(str_cpy, del);

	/* check if an empty command was entered */
	if (token == NULL)
	{
		return (NULL);
	}
	buffer[j] = strdup(token);
	if (buffer[j] == NULL)
	{
		_print("Error tokenizing");
		exit(0);
	}
	for (j = 1; j < token_count; j++)
	{
		token = strtok(NULL, del);
		/*buffer[j] = malloc(sizeof(char) * strlen(token));*/
		buffer[j] = strdup(token);
		/*strcpy(buffer[j], token);*/
		if (buffer[j] == NULL)
		{
			while (j + 1)
			{
				free(buffer[j]);
				j--;
			}
			free(buffer);
			free(str_cpy);
			break;
		}
	}
	buffer[j] = NULL;
	free(str_cpy);
	return (buffer);
}
