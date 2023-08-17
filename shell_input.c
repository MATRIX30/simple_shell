#include "shell.h"

/**
 * input_buf - buffers a chain of commands
 * @info: parameter struct
 * @buf: address of buffer
 * @len: address of length variables
 *
 * Return: bytes read
 */
ssize_t input_buf(info_t *info, char **buf, size_t *len)
{
ssize_t r = 0;
ssize_t len_p = 0;

do {
if (!*len) /* if nothunf is left in the buffer, fill it */
{
/*bfree((void **)info->cmd_buf);*/
free(*buf);
*buf = NULL;
signal(SIGINT, sigintHandler);
#if USE_GETLINE
r = getline(buf &len_p, stdin);
#else
r = _getline(info, buf, &len_p);
#endif

if (r > 0)
{
if ((*buf)[r - 1] == '\n')
{
(*buf)[r - 1] = '\0'; /* remove trailing newline */
r--;
}
info->linecoount_flag = 1;
remove_comments(*buf);
build_history_list(info, *buf, info->histcount++);
/* if (_strchr(*buf, ';')) is this a command chain? */
{
*len = r;
info->cmd_buf = buf;
}
}
}
} while (r == -1 && errno == EINTR);

return (r);
}

/**
 * get_input - gets a line minus the new line
 * @info: pointer parameter struct
 *
 * Return: bytes read
 */
ssize_t get_input(info_t *info)
{
static char *buf; /* the ';' command chain buffer */
static size_t i, j, len;
ssize_t r = 0;
char **buf_p = &(info->arg), *p;

_putchar(BUF_FLUSH);
r = input_buf(info, &buf
