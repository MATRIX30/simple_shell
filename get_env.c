#include "shell.h"

/**
 * get_environ - function returns the string environ
 * @info: element containtd potential argumenrs
 *
 * Return: pointer to the string arrary of environment variables
 */
char **get_environ(info_t *info)
{
info->environ = (!info->environ || info->env_changed) ?
list_to_strings(info->env) : info->environ;
info->env_changed = 0;

return (info->environ);
}

/**
 * _unsetenv - removes environment variable
 * @info: pointer to the info_t struct containing env linked list
 * @var: variable to remove
 *
 * Return: 1 if variable is removed, otherwise 0
 */
int _unsetenv(info_t *info, char *var)
{
list_t *curr = info->env;
size_t index = 0;
char *str;

if (!curr || !var)
return (0);

while (curr)
{
str = starts_with(curr->str, var);
if (str && *str == '=')
{
info->env_changed = delete_node_at_index(&(info->env),
index);
curr = info->env;
continue;
}
curr = curr->next;
index++;
}
return (info->env_changed);
}

/**
 * _setenv - adds or modifies an environment variable
 * @info: pointer to struct containing environment variables
 * @var: name of environment variable to add or modify
 *
 * Return: 0 on success, 1 on failure
 */
int _setenv(info_t *info, char *var, char *value)
{
char *buf = NULL;
list_t *node;
char *p;

/* check if var and value exist */
if (!var || !value)
return (0);

/* allocate memory for buf */
buf = malloc(_strlen(var) + _strlen(value) + 2);
if (!buf)
return (1);

/* concatenate var, '=', and value to buf */
_strcpy(buf, var);
_strcat(buf, "=");
_strcat(buf, value);

/*check if var already exists */
node = info->env;
while (node)
{
p = starts_with(node->str, var);
if (p && *p == '=')
{
/* free the old value and replace it with buf */
free(node->str);
node->str = buf;
info->env_changed = 1;
return (0);
}
node = node->next;
}

/* add buf to the end of the list */
add_node_end(&(info->env), buf, 0);
free(buf);
info->env_changed = 1;
return (0);
}
