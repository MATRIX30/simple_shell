#include "main.h"
/**
* This file contains various utilities used in our program
* they include toools for freeing memory on our defined 
* datastructures
*/

/**
* free_array - free's a character array of strings
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
