#include "simple_shell.h"

/**
 * allocate_memory_for_table - creates space im memory for table.
 * @size: The expected size of the table in bytes.
 *
 * Return: If sucess -- pointer to table; NULL -- otherwise.
 */
CommandTable_t *allocate_memory_for_table(unsigned long int size)
{
	CommandTable_t *table;
	unsigned long int i;

	table = malloc(sizeof(CommandTable_t));
	if (table == NULL)
		return (NULL);

	table->size = size;
	table->array = malloc(sizeof(CommandNode_t *) * size);
	if (table->array == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
		table->array[i] = NULL;

	return (table);
}

/**
 * create_command_table - creates the command table and fills it in
 * @table: a pointer to where the table is supposed to go in memory
 * 
 * Return: Whether or not it failed, 0 if it was created, 1 if not --
*/
int create_command_table(CommandTable_t **table)
{
	(void)table;
	/* Placeholder */
}

/**
 * free_command_table - Deletes the command table from memory
 * @table: A pointer to the command table.
 */
void free_command_table(CommandTable_t *table)
{
	CommandTable_t *head = table;
	CommandNode_t *node, *tmp;
	unsigned long int i;

	for (i = 0; i < table->size; i++)
	{
		if (table->array[i] != NULL)
		{
			node = table->array[i];
			while (node != NULL)
			{
				tmp = node->next;
				free(node->name);
				free(node);
				node = tmp;
			}
		}
	}
	free(head->array);
	free(head);
}
