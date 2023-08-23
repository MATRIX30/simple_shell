#include "shell.h"

/**
 * add_node - adds a node to the start of the list
 * @head: address of poitnter to head node
 * @str: str field of node
 * @num: node index used bu history
 *
 * Reyurn: pointer to new node, NULL on failure
 */
list_t *add_node(list_t **head, const char *str, int num)
{
list_t *new_node;

if (!head)
return (NULL);

new_node = malloc(sizeof(list_t));
if (!new_node)
return (NULL);

new_node->str = NULL;
new_node->next = *head;
new_node->num = num;

if (str)
{
new_node->str = strdup(str);
if (!new_node->str)
{
free(new_node);
return (NULL);
}
}

*head = new_node;
return (new_node);
}

/**
 * add_node_end - adds node to the end of the list
 * @head: address of pointer to head node
 * @str: str field of node
 * @num: node index used by history
 *
 * Return: pointer to new node, NULL on failure
 */
list_t *add_node_end(list_t **head, const char *str, int num)
{
list_t *new_node, *last;

if (!head)
return (NULL);

new_node = malloc(sizeof(list_t));
if (!new_node)
return (NULL);

new_node->str = NULL;
new_node->next = NULL;
new_node->num = num;

if (str)
{
new_node->str = strdup(str);
if (!new_node->str)
{
free(new_node);
return (NULL);
}
}

if (*head == NULL)
{
*head = new_node;
return (new_node);
}

last = *head;
while (last->next != NULL)
last = last->next;

last->next = new_node;
return (new_node);
}

/**
 * print_list_str - prints only the str element of a list_t linked list
 * @h: pointer to first node
 *
 * Return: number of nodes printed
 */

size_t print_list_str(const list_t *h)
{
size_t n = 0;

while (h != NULL)
{
printf("%s\n", h->str ? h->str : "(nil)");
h = h->next;
n++;
}

return (n);
}

/**
 * delete_node_at_index - deletes node at given index
 * @head: address of pointer to first node
 * @index: index of node to delete
 *
 * Return: 1 on success, 0 on failure
 */
int delete_node_at_index(list_t **head, unsigned int index)
{
list_t *node, *prev_node;
unsigned int i = 0;

if (index == 0)
{
node = *head;
*head = node->next;
free(node->str);
free(node);
return (1);
}

prev_node = *head;
node = prev_node->next;

while (node)
{
if (i == index)
{
prev_node->next = node->next;
free(node->str);
free(node);
return (1);
}

i++;
prev_node = node;
node = node->next;
}

return (0);
}

/**
 * free_list - frees all nodes of a list
 * @head_ptr: address of pointer to head node
 *
 * Return: void
 */
void free_list(list_t **head_ptr)
{
list_t *node, *next_node, *head;

if (!head_ptr || !*head_ptr)
return;
head = *head_ptr;
node = head;
while (node)
{
next_node = node->next;
free(node->str);
free(node);
node = next_node;
}
*head_ptr = NULL;
}
