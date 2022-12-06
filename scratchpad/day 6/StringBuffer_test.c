#include "simple_shell.h"

/**
* check_stringbuff - Prints all strings left in buffer
* @current_node: the current_node of the list
*/
void check_stringbuff(const StringBuffer_t *current_node)
{
	size_t nodes = 0;

	while (current_node)
	{
		printf("INDEX[%lu]: %s\x0a", nodes, current_node->contents);
		nodes++;
		current_node = current_node->next;
	}
}
/**
 * get_index - Locates a node in a StringBuffer_t.
 * @top_node: The top_node of the StringBuffer_t list.
 * @index: The node to locate.
 *
 * Return: The address of the located node (or NULL if it didn't exist)
 */
StringBuffer_t *get_index(StringBuffer_t *top_node, unsigned int index)
{
	for (; index != 0; index--)
	{
		if (top_node == NULL)
			return (NULL);
		top_node = top_node->next;
	}
	return (top_node);
}
