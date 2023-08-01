#include "lists.h"
#include <string.h>
#include <stdio.h>

/**
 * add_node - Adds a new node at the beginning of a `list_t` list.
 * @head: Double pointer to the head of the list.
 * @str: String to be saved in the new node, must be duplicated.
 *
 * Return: Address of the new element or NULL if it fails.
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new_node;
	int str_len = 0;

	while (str[str_len] != '\0')
		str_len++;

	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
	{
		free(new_node);
		return (NULL);
	}

	new_node->str = strdup(str);
	if (new_node->str == NULL)
	{
		free(new_node);
		return (NULL);
	}

	new_node->len = str_len;
	new_node->next = *head;

	*head = new_node;
	return (*head);
}
