#include "shell.h"

/**
 * _memset - fills the first n byts of the memory area  pointed to by s
 * with the constant byte b
 * @s: pointer to memory area
 * @b: constant byte
 * @n: number of bytes to fill
 *
 * Return: pointer to the filled memory area
 */
char *_memset(char *s, char b, unsigned int n)
{
/*
 * this function fills the first n bytes of the memory area
 * pointed  to by s with the constant byte b
 */

unsigned int i;

for (i = 0; i < n; i++)
{
s[i] = b;
}

return (s);
}

/**
 * ffree - frees a string array
 * @str_array: array of strings to free
 * this function free each string in the given array, and
 * then free the array itself. if the array is NULL, it does nothing.
 */
void ffree(char **str_array)
{
char **array_copy = str_array;

if (!str_array)
return;

while (*str_array)
free(*str_array++);

free(array_copy);
}

/**
 * _realloc - reallocates a memory block
 * @ptr: pointer to memory previously allocated
 * @old_size: size of the allocated space for @ptr
 * @new_size: new size to allocate
 *
 * Return: pointer to reallocated memory block
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
char *new_ptr;

/* if ptr is NULL, equivalent to malloc(new_size) */
if (!ptr)
return (malloc(new_size));

/* if new_size is zero and ptr is not NULL, equivalent to free(ptr) */
if (!new_size)
return (free(ptr), NULL);

/* if new_size is equal to the old_size, do not allocate memory */
if (new_size == old_size)
return (ptr);

/* allocate new memory block of given size */
new_ptr = malloc(new_size);
if (!new_ptr)
return (NULL);

/* copy contents of old memory block to new memory block */
old_size = old_size < new_size ? old_size : new_size;
while (old_size--)
new_ptr[old_size] = ((char *)ptr)[old_size];

/* free old memory block */
free(ptr);

/* return pointer to the newly allocated memory block */
return (new_ptr);
}

