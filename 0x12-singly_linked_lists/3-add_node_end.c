#include "lists.h"
#include <string.h>
#include <stdio.h>

/**
 * add_node_end - Adds a new node at the end of a `list_t` list.
 * @head: Double pointer to the head of the list.
 * @str: String to be duplicated into the new node.
 *
 * Return: Address of the new element or NULL if it fails.
 */
list_t *add_node_end(list_t **head, const char *str)
{
    list_t *last;
    list_t *new_elem;
    int str_len = 0;

    last = *head;
    while (last && last->next != NULL)
        last = last->next;

    while (str[str_len] != '\0')
        str_len++;

    new_elem = malloc(sizeof(list_t));
    if (new_elem == NULL)
    {
        free(new_elem);
        return (NULL);
    }
    new_elem->str = strdup(str);
    if (new_elem->str == NULL)
    {
        free(new_elem);
        return (NULL);
    }
    new_elem->len = str_len;
    new_elem->next = NULL;

    if (last)
        last->next = new_elem;
    else
        *head = new_elem;

    return (new_elem);
}
