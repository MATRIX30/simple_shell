#include "shell.h"

/**
 * is_chain - determined whether the current position in the
 * command buffer represents a chain operater
 *
 * @info: pointer to struct that contains current command buffer type
 * @buf: pointer to the command buffer string
 * @p: pointer to the current position in the command buffer string
 *
 * Return: 1 if current position represents chain operator, 0 otherwise
 */
int _ischain(info_t *info, char *buf, size_t *p)
{
size_t j = *p;

switch (buf[j])
{
case '|':
if (buf[j + 1] == '|')
{
buf[j] = 0;
info->cmd_buf_type = CMD_OR;
j++;
}
break;

case '&':
if (buf[j +1] == '&')
{
buf[j] = 0;
info->cmd_buf_type = CMD_AND;
j++;
}
break;

case ';':
buf[j] = 0;
info->cmd_buf_type = CMD_CHAIN;
break;

default:
return (0);
}

*p = j;
return (1);
}

/**
 * check_chain - check for command chaining operators
 * and pdate buffer accordingly
 *
 * @info: pointer to info_t struct
 * @buf: pointer to command buffer
 * @p: pointer to current position in buffer
 * @i: current index
 * @len: length of bugger
 */

void check_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len)
{
size_t j = *p;

/* check for '&&' operator and update buffer */
if (info->cmd_buf_type == CMD_AND && info->status)
{
buf[i] = '\0';
j = len;
}

/* check for '||' operator and update buffer*/
if (info->cmd_buf_type == CMD_OR && !info->status)
{
buf[i] = '\0';
j = len;
}

*p = j;
}

/**
 * replace_alias - replaces a command with its aliased values,
 * if it exits
 *
 * @info: pointer to info_t struct
 * Return: on success 1, 0 on failure
 */
int replace_alias(info_t *info)
{
list_t *node;
char *p;
int i = 0;

while (i < 10)
{
node = node_starts_with(info->alias, info->argv[0], '=');
if (!node)
return (0);
free(info->argv[0]);
p = _strchr(node->str, '=');
if (!p)
return (0);
p = _strdup(p + 1);
if (!p)
return (0);
info->argv[0] = p;
i++;
}
return (1);
}

/**
 * replace_vars - replaces variable names with their valuse
 * @info: pointer to info_t struct containing
 * the variables to replace
 *
 * Return: Always 0
 */
int replace_vars(info_t *info)
{
int i;
list_t *node;

for (i = 0; info->argv[i]; i++)
{
if (info->argv[i][0] != '$' || !info->argv[i][1])
continue;

if (!strcmp(info->argv[i], "$"))
{
/* replace with exit status value */
replace_string(&info->argv[i], _strdup(convert_number(info->status, 10, 0)));
}
else if (!strcmp(info->argv[i], "$$"))
{
/* replaces with process ID value */
replace_string(&info->argv[i], _strdup(convert_number(getpid(), 10, 0)));
}
else
{
/* look for environment variable and replace with its value*/
node = node_starts_with(info->env, &info->argv[i][1], '=');
if (node)
{
replace_string(&info->argv[i], _strdup(_strchr(node->str, '=') +1));
}
else
{
/* no matching environment variable found; replace with empty string */
replace_string(&info->argv[i], _strdup(""));
}
}
}

return (0);
}

/**
 * replace_string - replaces old string with anew one
 * @old: pointer to string that needs to be replaced
 * @new: pointer to new string
 *
 *
 *
 *
 *
 * Return: void
 */
int replace_string(char **old, char *new)
{
free(*old);
*old = new;
return (1);
}
