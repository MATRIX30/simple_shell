#include "main.h"
/**
* This file contains various utilities used in our program
* they include toools for freeing memory on our defined 
* datastructures
*/

/**
* free_array - free a character array of strings
* @arr: array of characters 
*/

void free_array(char **arr)
{
	while (*arr)
	{
		free(*arr);
		arr++;
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
	extern char **environ; /* environmental variable*/

	int name_len = _strlen(name); 

    /* loop through the environment variables */
    while (*environ)
    {
        /* compare the name argument with the current variable */
        if (strncmp(name, *environ, name_len) == 0 && (*environ)[name_len] == '=')
        {
            /* return the value after the '=' sign */
            return ((*environ) + name_len + 1);
        }
        environ++; 
    }
    return (NULL);
}


/**
* _strlen - functiont to calculate the length of a string excluding '\0'* @str: strinng whose lenght is to be computed
* Return: length of string
*/

int _strlen(const char *str)
{
	int len = 0;

	if (str == NULL || *str == '\0')
		return (0);

	while(*str != '\0')
	{
		len++;
		str++;
	}
	return (len);
}

/**
* _strcat - function to concate 2 strings and return results
* @str1: 1st string
* @str2: 2nd string
* Return: a new string made up of str1 and str2
*/
/*
char *_strcat(char *str1, char *str2)
{
	char *res;
	int len1 = 0;
	int len2 = 0;


}
*/
/**
* _strcat - string concatenation function
* @dest: destination string 
* @src: source string
* Return concatenated string
*/
char *_strcat(char *dest, char *src)
{
        int i = 0;

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

