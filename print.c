#include "main.h"
/**
* _putchar - function to print a single character
* @c: character to be printed
* Return: number of characters written
*/

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
* _print - function to print a string based on _putchar
* @str: string parameter to print
* Return: number of characters to print
*/

int _print(char *str)
{
	int i = 0;

	if (str == NULL)
	{
		/* Handling of Null pointer */
		return (1);
	}

	while (*str != '\0')
	{
		_putchar(*str);
		str++;
		i++;
	}
	return (i);
}


/**
* _putcharerr - function to print a single error character
* @c: character to be printed
* Return: number of characters written
*/

int _putcharerr(char c)
{
	return (write(2, &c, 1));
}
/**
* _printerr - function to prints error string based on _putchar
* @str: string parameter to print
* Return: number of characters to print
*/

int _printerr(char *str)
{
	int i = 0;

	while (*str != '\0')
	{
		_putcharerr(*str);
		str++;
		i++;
	}
	return (i);
}
