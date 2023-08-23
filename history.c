#include "shell.h"

/**
* get_history_file - Returns an allocated string containing
* the path of the history file.
* @info: A pointer to the parameter struct.
*
* Return: On success, returns the path of the history file.
* Otherwise, returns NULL.
*/
char *get_history_file(info_t *info)
{
char *dir = _getenv(info, "HOME=");
char *buf = malloc(sizeof(char) *
(_strlen(dir) + _strlen(HIST_FILE) + 2));
if (!dir || !buf)
return (NULL);
buf[0] = 0;
_strcpy(buf, dir);
_strcat(buf, "/");
_strcat(buf, HIST_FILE);
return (buf);
}

/**
* write_history - writes the contents of
* info->history to the history file
* @info: a pointer to the info_t struct
*
* Return: On success, returns 1. On failure, returns -1.
*/
int write_history(info_t *info)
{
ssize_t fd;
char *filename = get_history_file(info);
list_t *node = info->history;
int ret = 1;

if (!filename)
return (-1);

fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
free(filename);
if (fd == -1)
return (-1);

while (node)
{
if (_putsfd(node->str, fd) == -1 || _putfd('\n', fd) == -1)
{
ret = -1;
break;
}
node = node->next;
}

if (_putfd(BUF_FLUSH, fd) == -1)
ret = -1;

if (close(fd) == -1)
ret = -1;

return (ret);
}



/**
* read_history - reads the command history from a file
* @info: a struct containing information about the shell
* This function reads the history of commands from a file and stores them in a
* linked list of history nodes. It then renumbers the history nodes to ensure
* that they are numbered sequentially starting from 1. If the history file is
* empty or cannot be read, or if the memory allocation fails, this function
* Return: returns 0. Otherwise, it returns the number of history nodes.
*/
int read_history(info_t *info)
{
int i, last = 0, linecount = 0;
ssize_t fd, rdlen, fsize = 0;
struct stat st;
char *buf = NULL, *filename = get_history_file(info);

if (!filename)
return (0);

fd = open(filename, O_RDONLY);
free(filename);
if (fd == -1)
return (0);
if (!fstat(fd, &st))
fsize = st.st_size;
if (fsize < 2)
return (0);
buf = malloc(sizeof(char) * (fsize + 1));
if (!buf)
return (0);
rdlen = read(fd, buf, fsize);
buf[fsize] = 0;
if (rdlen <= 0)
return (free(buf), 0);
close(fd);
for (i = 0; i < fsize; i++)
if (buf[i] == '\n')
{
buf[i] = 0;
build_history_list(info, buf + last, linecount++);
last = i + 1;
}
if (last != i)
build_history_list(info, buf + last, linecount++);
free(buf);
info->histcount = linecount;
while (info->histcount-- >= HIST_MAX)
delete_node_at_index(&(info->history), 0);
renumber_history(info);
return (info->histcount);
}

/**
* build_history_list - adds an entry to the history linked list
* @info: Structure containing arguments and history
* @buf: buffer containing the command to add
* @linecount: current line number in history
* Return: Always returns 0
*/
int build_history_list(info_t *info, char *buf, int linecount)
{
list_t *new_node = NULL;

if (info->history)
new_node = info->history;

add_node_end(&new_node, buf, linecount);

if (!info->history)
info->history = new_node;

return (0);
}

/**
* renumber_history - renumbers the history linked list after changes
* @info: Structure containing potential arguments. Used to maintain
*
* Return: the new histcount
*/
int renumber_history(info_t *info)
{
list_t *node = info->history;
int i = 0;

while (node)
{
node->num = i++;
node = node->next;
}
return (info->histcount = i);
}
