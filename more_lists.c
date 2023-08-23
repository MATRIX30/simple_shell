#include "shell.h"

/**
 * list_len - function determines length of linked list
 * @h: pointer to first node
 *
 * Return: size of the list
 */
size_t list_len(const list_t *h)
{
if (!h)
return (0);
else
return (1 + list_len(h->next));
}

/**
 * list_to_strings - conversts a linked list to an array of strings
 * @head: pointer to head of the linked list
 *
 * Return: array of string containing the strings from the linked list
 */
char **list_to_strings(list_t *head)
{
list_t *node = head;
size_t i = list_len(head), j;
char **strs;
char *str;

if (!head || !i)
return (NULL);

strs = malloc(_strlen(node->str) + 1);
if (!strs)
return (NULL);

for (i = 0; node; node = node->next, i++)
{
str = malloc(_strlen(node->str) + 1);
if (!str)
{
for (j = 0; j < i; j++)
free(strs[j]);
free(strs);
return (NULL);
}
str =  _strcpy(str, node->str);
strs[i] = str;
}

strs[i] = NULL;
return (strs);
}

/**
 * print_list - prints all the elements of a linked list
 * @head: pointer to head of the list
 *
 * Return: number of nodes in the list
 */
size_t print_list(const list_t *head)
{
size_t i  = 0;

while (head)
{
_puts(convert_number(head->num, 10, 0));
_putchar(':');
_putchar(' ');
_puts(head->str ? head->str : "(nil)");
_puts("\n");
head = head->next;
i++;
}

return (i);
}

/**
 * node_starts_with - finds the first node in a linked list
 * with a string value, starts witha given prefix
 * and has an optional specific character at a given
 * position
 * @node: pointet to first node of the linked list
 * @prefix: pointer to prefix string to search for
 * @c: optional character to match at the specified position
 *
 * Return: pointer to the first node that matched the criteria
 * or NULL if none is found
 */
list_t *node_starts_with(list_t *node, char *prefix, char c)
{
char *str_start = NULL;

while (node)
{
str_start = starts_with(node->str, prefix);
if (str_start && ((c == -1) || (*str_start == c)))
return (node);
node = node->next;
}

return (NULL);
}

/**
 * get_node_index - returns the index of a given node in a linked list
 * @head: pointer to the head of the list
 * @node: pointer to the node 
 *
 * Return: index of the node, or -1 if the node is not found
 */
ssize_t get_node_index(list_t *head, list_t * node)
{
ssize_t i = 0;

while (head)
{
if (head == node)
return (i);
head = head->next;
i++;
}
return (-1);
}

