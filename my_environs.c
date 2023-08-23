#include "shell.h"

/**
 * _myenv - prints the current environment variables
 * @info: pointer to structure of tyoe info_t
 * used to maintain constant function prototype
 * Return: Always 0
 */
int _myenv(info_t *info)
{
/* call_print_list_str function from shell.h */
print_list_str(info->env);

/* always return 0 */
return (0);
}

/**
 * _getenv - returns the value of an envrironment variable
 * @info: struct containing potential arguments
 * @name: name of the environment variable to retrieve
 * Return: value of the environment variable, NULL if not found
 */

char *_getenv(info_t *info, const char *name)
{
list_t *env_node = info->env;
char *value;

while (env_node)
{
value = starts_with(env_node->str, name);
if (value && *value)
return (value);
env_node = env_node->next;
}
return (NULL);
}

/**
 * _mysetenv - initializes a new environment variable or
 * modify existing one
 * @info: struct containing potential arguments
 *
 * Return: always 0
 */
int _mysetenv(info_t *info)
{
if (info->argc != 3)
{
_eputs("Incorrect number of arghuments \n");
return (1);
}
if (_setenv(info, info->argv[1], info->argv[2]))
return (0);
return (1);
}

/**
 * _myunsetenv - removes an environemnt variable
 * @info: struct containing potential arguments
 *
 * Return: Always 0
 */
int _myunsetenv(info_t *info)
{
int index;

/* check if there are enough arguments */
if (info->argc == 1)
{
_eputs("Too few arguments.\n");
return (1);
}

/* loop through each argument and remove the corresponding environment */
for (index = 1; index < info->argc; index++)
{
_unsetenv(info, info->argv[index]);
}

/* return 0 to indicate successful completetion */
return (0);
}

/**
 * populate_env_list - populates linked list with environment variables
 * @info: pointer to struct containing potential arguments
 *
 * Return: 0 on success, 1 on failure
 */
int populate_env_list(info_t *info)
{
list_t *head = NULL;
size_t index;

/* traverse through environment variables */
for (index = 0; environ[index]; index++)
{
/* add the variable to the end of the lsit */
add_node_end(&head, environ[index], 0);
}

/* update the info struct with the head of the list */
info->env = head;

/* return success */
return (0);
}
