#include "main.h"
/**
* free_array - free a character array of strings
* @arr: array of characters
*/
void free_array(char **arr)
{
	int i = 0;

	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

/**
* _getenv- gets the value of the environmental variable specified by @name
* @name: name of environmental variable
* Return: value of environmental variable  or NULL otherwise
*/
char *_getenv(const char *name)
{

	int name_len = _strlen(name);

	if (environ == NULL || *environ == NULL)
	{
		return (NULL);
	}
	/* loop through the environment variables */
	while (*environ)
	{
		/* compare the name argument with the current variable */
		if (strncmp(name, *environ, name_len) == 0)
		{
			if ((*environ)[name_len] == '=')
			{
				/* return the value after the '=' sign */
				return ((*environ) + name_len + 1);
			}
		}
		environ++;
	}
	return (NULL);
}


/**
* _strlen - functiont to calculate the length of a string excluding '\0'
* @str: strinng whose lenght is to be computed
* Return: length of string
*/

int _strlen(const char *str)
{
	int len = 0;

	if (str == NULL || *str == '\0')
		return (0);

	while (*str != '\0')
	{
		len++;
		str++;
	}
	return (len);
}

/**
* _strcat - string concatenation function
* @dest: destination string
* @src: source string
* Return: concatenated string
*/
char *_strcat(char *dest, char *src)
{
	int i = 0;

	if (dest == NULL)
		return (src);
	if (src == NULL)
		return (dest);
	while (*(dest + i))
	{
		i++;
	}

	while (*(src))
	{
		*(dest + i) = *(src);
		i++;
		src++;
	}
	*(dest + i) = '\0';
	return (dest);
}

/**
* _strcpy - function to copy from one buffer to another
* @dest: destination buffer
* @src: source buffer
* Return: char
*/

char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (*(src + i) != '\0')
	{
		*(dest + i) = *(src + i);
		i++;
	}
	*(dest + i) = '\0';
	return (dest);
}
