#include "monty.h"
#include "parser.h"

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
    unsigned int index, was_not_set;
    size_t size_of_table = (sizeof(CommandNode_t) * NUM_OF_OPS);
    char opcodes[NUM_OF_OPS][NAME_BUFFER_SIZE] = OPCODE_NAMES;
    Command func_pointers[NUM_OF_OPS] = FUNCTIONS;

    *table = allocate_memory_for_table(size_of_table);
    if (table == NULL)
        return (EXIT_FAILURE);

    for (index = 0; index < NUM_OF_OPS; index++)
    {
        was_not_set = set_command(*table, opcodes[index], func_pointers[index]);
        if (was_not_set)
        {
            free_command_table(*table);
            return (EXIT_FAILURE);
        }
    }
    return (EXIT_SUCCESS);
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
				free(node->key);
				free(node);
				node = tmp;
			}
		}
	}
	free(head->array);
	free(head);
}
