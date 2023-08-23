#include "main.h"
/**
* _atoi - converts string to integer
* @s: string of characters
*
* Return: number converted from string or 0
*/
int _atoi(char *s)
{
	int i = 0, sign = 1;
	int64_t number = 0;

	while (s[i] != '\0')
	{
		if (number == 0 && s[i] == '-')
		{
			sign *= -1;
		}
		else
		{
			if (isdigit(s[i]))
			{
				number = 10 * number + s[i] - 48;
			}
			else if (number != 0)
			{
				break;
			}
		}
		i++;
	}
	return (number * sign);
}

/**
 * _strtok - function to tokenize a string based on some delimiter
 * @str: the string to tokenize
 * @del: delimiter
 * Return: token and null if emptpy
*/
char *_strtok(char *str, const char *del)
{
	static char *terminator;
	char *start;

	if (str != NULL)
	{
		terminator = str;
	}
	if (terminator == NULL)
	{
		return (NULL);
	}

	while (*terminator && strchr(del, *terminator))
	{
		terminator++;
	}
	if (*terminator == '\0')
	{
		return (NULL);
	}

	start = terminator;
	while (*terminator && !strchr(del, *terminator))
	{
		terminator++;
	}
	if (*terminator)
	{
		*terminator = '\0';
		terminator++;
	}
	return (start);
}
