#include "monty.h"

/**
 * add_to_end - add a stringbuffer to the doubly linked list
 * @top_node: top node of the list
 * @new_str: the string to be added
 *
 * Return: pointer to the new node in the list.
*/
StringBuffer_t *add_to_end(StringBuffer_t **top_node, const char *new_str)
{
	char *staging_buff;
	StringBuffer_t *new_buffer_node, *last_node;

	new_buffer_node = malloc(sizeof(StringBuffer_t));
	if (new_buffer_node == NULL)
		return (NULL);

	staging_buff = strdup(new_str);
	if (staging_buff == NULL)
	{
		free(new_buffer_node);
		return (NULL);
	}
	new_buffer_node->contents = staging_buff;
	new_buffer_node->next = NULL;

	if (*top_node == NULL)
	{
		new_buffer_node->prev = NULL;
		*top_node = new_buffer_node;
		return (new_buffer_node);
	}
	last_node = *top_node;
	while (last_node->next)
		last_node = last_node->next;
	last_node->next = new_buffer_node;
	new_buffer_node->prev = last_node;

	return (new_buffer_node);
}

/**
 * add_string - add a stringbuffer to the doubly linked list
 * @top_node: top node of the list
 * @new_str: the string to be added
 *
 * Return: pointer to the new node in the list.
*/
StringBuffer_t *add_string(StringBuffer_t **top_node, const char *new_str)
{
	char *staging_buff;
	StringBuffer_t *new_buffer_node;

	new_buffer_node = malloc(sizeof(StringBuffer_t));
	if (new_buffer_node == NULL)
		return (NULL);

	staging_buff = strdup(new_str);
	if (staging_buff == NULL)
	{
		free(new_buffer_node);
		return (NULL);
	}
	new_buffer_node->contents = staging_buff;
	new_buffer_node->next = *top_node;
	if (*top_node != NULL)
		(*top_node)->prev = new_buffer_node;
	*top_node = new_buffer_node;

	return (new_buffer_node);
}
/**
* free_stringbuff - free a doubly linked list
* @current_node: first node in the list
*/
void free_stringbuff(StringBuffer_t *current_node)
{
	StringBuffer_t *next_node;

	while (current_node)
	{
		next_node = current_node->next;
		free(current_node);
		current_node = next_node;
	}
}
/**
 * pop_string - Deletes the top node of string buffer
 * @top_node: A pointer to the address of buffer
 *
 * Return: If the linked list is empty - 0.
 *         Otherwise - The top_node node's data (n).
 */
char *pop_string(StringBuffer_t **top_node)
{
	StringBuffer_t *buff_node;
	char *retrieved_string;

	if (*top_node == NULL)
		return (NULL);

	buff_node = *top_node;
	retrieved_string = (*top_node)->contents;
	*top_node = (*top_node)->next;

	free(buff_node);

	return (retrieved_string);
}
