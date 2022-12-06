#include "parser.h"

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
/**
 * set_command - Add or update an element in a hash table.
 * @table: A pointer to the hash table.
 * @key: The key to add - cannot be an empty string.
 * @func: The value associated with key.
 *
 * Return: asdf
 */
int set_command(CommandTable_t *table, const char *keyword, Command func)
{
	CommandNode_t *new;
	unsigned long int index;

	if (table == NULL || keyword == NULL || *keyword == '\0' || func == NULL)
		return (EXIT_FAILURE);

	new = malloc(sizeof(CommandNode_t));
	if (new == NULL)
		return (EXIT_FAILURE);

	index = key_index((const unsigned char *)keyword, table->size);
	new->key = strdup(keyword);
	if (new->key == NULL)
	{
		free(new);
		return (0);
	}
	new->f = func;
	new->next = table->array[index];
	table->array[index] = new;

	return (EXIT_SUCCESS);
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
unsigned long int key_index(const unsigned char *keyword, unsigned long int size)
{
	return (hash_djb2(keyword) % size);
}
