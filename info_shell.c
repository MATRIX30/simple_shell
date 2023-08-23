#include "shell.h"

/**
 * clear_info - initializes info_t struct
 * @info: struct address
 *
 * This function initializes members of the info_t struct pointed
 * to by info
 *
 * It sets arg, argv, and path to NULL and argc to 0
 */
void clear_info(info_t *info)
{
info->arg = NULL;
info->argv = NULL;
info->path = NULL;
info->argc = 0;
}

/**
 * set_info - sets up the info_t struct
 * @info: info_t struct address to be updated
 * @av: double pointer to array of arguments
 */
void set_info(info_t *info, char **av)
{
int i = 0;

/* set the filename */
info->fname = av[0];

/* check if argument exists */
if (info->arg)
{
/*split the argument into an array of arguments */
if (!info->argv)
{
info->argv = malloc(sizeof(char *) * 2);
if (info->argv)
{
info->argv[0] = _strdup(info->arg);
info->argv[1] = NULL;
}
}

/* Count the number of arguments */
for (i = 0; info->argv && info->argv[i]; i++)
;
info->argc = i;

/* replace alias with its value */
replace_vars(info);
}
}

/**
 * free_info - frees the memory allocated for info_t struct
 * @info: pointer to info_t struct
 * @all: integer flag to free all allocated memory
 */
void free_info(info_t *info, int all)
{
ffree(info->argv);
info->argv = NULL;
info->path = NULL;
if (all)
{
if (!info->cmd_buf)
free(info->arg);
if (info->env)
free_list(&(info->env));
if (info->history)
free_list(&(info->history));
if (info->alias)
free_list(&(info->alias));
ffree(info->environ);
info->environ = NULL;
bfree((void **) info->cmd_buf);
if (info->readfd > 2)
close(info->readfd);
_putchar(BUF_FLUSH);
}
}
