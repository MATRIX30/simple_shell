#include "shell.h"

/**
 * _eputs - prints a string to the standard error
 * @str: string to be printed
 *
 * Return: Nothing
 */
void _eputs(char *str)
{
int index = 0;

if (!str)
return;

while (str[index] != '\0')
{
_putfd(str[index], STDERR_FILENO);
index++;
}
}

/**
 * _eputchar - writes character c to stderr
 * @character: character to print
 *
 * Return: On Success 1
 * -1 on error, errno is set appropriately
 */
int _eputchar(char character)
{
static int buffer_index;
static char buffer[WRITE_BUF_SIZE];

if (character == BUF_FLUSH || buffer_index >= WRITE_BUF_SIZE)
{
write(STDERR_FILENO, buffer, buffer_index);
buffer_index = 0;
}
if (character != BUF_FLUSH)
buffer[buffer_index++] = character;

return (1);
}

/**
 * _putfd - writes character to given file descriptor
 * @c: character to be printed
 * @fd: file descriptor to write to
 *
 * Return: On success 1
 * On failure 0, errno is set appropriately
 */
int _putfd(char c, int fd)
{
static int buffer_index;
static char buffer[WRITE_BUF_SIZE];

/* FLush the buffer if the character is the flash signal */
if (c == BUF_FLUSH || buffer_index >= WRITE_BUF_SIZE)
{
write(fd, buffer, buffer_index);
buffer_index = 0;
}

/* add character to buffer if no flush signal */
if (c != BUF_FLUSH)
buffer[buffer_index++] = c;

return (1);
}

/**
 * _putsfd - writes input string to given file descriptor
 * @str: string to write
 * @fd: file descriptor to write to
 *
 * Return: number of characters written
 *
 */
int _putsfd(char *str, int fd)
{
int num_chars = 0;

if (!str)
return (0);

while (*str)
{
num_chars += _putfd(*str++, fd);
}

return (num_chars);
}
