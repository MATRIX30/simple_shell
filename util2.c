#include "main.h"
int _atoi(char *s);
ssize_t _getline(char **lineptr, size_t *n, int fd);
char *_strtok(char *str, const char *del);
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

/**
* _getline - function to take data from stream and store in buffer
* @lineptr: pointer to the buffer where data will be stored
* @n: number of bytes to be written
* @fd: file descriptor to the stream
* Return: number of bytes writteni -1 if fail
*/
ssize_t _getline(char **lineptr, size_t *n, int fd)
{
	static char buffer[BUFFER_SIZE];
	static size_t ind;
	static size_t len;
	size_t i = 0;
	char *stream;

	ind = 0;
	len = 0;
	if (lineptr == NULL || n == NULL)
	{
		return (-1);
	}

	if (*lineptr == NULL)
	{
		*n = BUFFER_SIZE;
		*lineptr = malloc(*n);
		if (*lineptr == NULL)
		{
			return (-1);
		}
	}

	stream = *lineptr;
	while (1)
	{
		if (ind >= len)
		{
			ind = 0;
			len = read(fd, buffer, BUFFER_SIZE);
			if (len <= 0)
			{
				return (len);
			}
		}
		while (ind < len && i < *n - 1 && buffer[ind] != '\n')
		{
			stream[i++] = buffer[ind++];
		}
		if (ind < len && buffer[ind] == '\n')
		{
			stream[i++] = buffer[ind++];
			stream[i] = '\0';
			return (i);
		}

		if (i >= *n - 1)
		{
			*n *= 2;
			stream = realloc(stream, *n);
			if (stream == NULL)
				return (-1);
			*lineptr = stream;
		}
	}
}

