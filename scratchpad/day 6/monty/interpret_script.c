#include "monty.h"

int interpret_script(MontyInterpreter_t **monty, ScriptReader_t **script)
{
	char next_line[255];

	while ((*script)->line_buffer)
	{
		snprintf(next_line, 255, "%s", pop_string(&((*script)->line_buffer)));
		printf("%s", next_line);
		(*monty)->operation_tokens = tokenize_string(next_line, " ");
		printf("COMMAND: %s\n", (*monty)->operation_tokens[0]);
		printf("ARGUMENT: %s", (*monty)->operation_tokens[1]);
	}
	return (EXIT_SUCCESS);
}
/**
 * get_command - Retrieve the value associated with a key in a hash table.
 * @table: A pointer to the hash table.
 * @key: The key to get the value of.
 *
 * Return: Tries to return pointer to function bound to keyword.
 */
Command get_command(const CommandTable_t *table, const char *keyword)
{
	CommandNode_t *node;
	unsigned long int index;

	if (table == NULL || keyword == NULL || *keyword == '\0')
		return (NULL);

	index = key_index((const unsigned char *)keyword, table->size);
	if (index >= table->size)
		return (NULL);

	node = table->array[index];
	while (node && strcmp(node->key, keyword) != 0)
		node = node->next;

	return ((node == NULL) ? NULL : node->f);
}
