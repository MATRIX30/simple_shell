#include "main.h"

int _putchar(char c)
{
	return(write(1, &c, 1));
}

int _print(char *str)
{
	int i = 0;
	while(*str != '\0')
	{
		_putchar(*str);
		str++;
		i++;
	}
	return (i);
}
