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
