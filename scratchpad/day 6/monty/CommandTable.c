#include "monty.h"

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
/**
 * hash_djb2 - Hash function implementing the djb2 algorithm.
 * @str: The string to hash.
 *
 * Return: The calculated hash.
 */
unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int hash;
	int c;

	hash = 5381;
	while ((c = *str++))
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

	return (hash);
}

/**
 * key_index - Get index where key/value pair should be stored in hash table.
 * @key: The key to get the index of.
 * @size: The size of the array of the hash table.
 *
 * Return: The index of the key.
 * Description: Uses the djb2 algorithm.
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
