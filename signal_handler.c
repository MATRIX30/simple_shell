#include "main.h"

/**
* signal_handle - this function handles various signals recieved at the terminal 
* @sig: integer signal recieved from terminal
* Return: 1 if signal was recieved and process successfully 0 otherwise
*/

void signal_hanlder(int sig)
{
	printf("Signal Has been recieved %d\n",sig);
}
