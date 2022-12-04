#include "monty.h"

/**
 * create_monty - create the interpreter
 * @self: double pointer back to monty
 *
 * Return: If there was a problem.
 */
int create_monty(MontyInterpreter_t **self)
{
	*self = malloc(sizeof(MontyInterpreter_t));
	if (*self == NULL)
		return (throw_error(COULDNT_MALLOC, 0, ""));

	(*self)->operation_tokens = NULL;
	(*self)->line_num = 0;

	(*self)->instructions = NULL;
	if (create_command_table(&((*self)->instructions)) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	(*self)->stack = NULL;
	if (initialize_stack(&((*self)->stack)) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	(*self)->error_triggered = 0;

	return (EXIT_SUCCESS);
}
/**
 * set_command - Add or update an element in a hash table.
 * @table: A pointer to the hash table.
 * @keyword: The key to add - cannot be an empty string.
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
 * initialize_stack- Initializes the stack_t stack
 * @stack_pointer: exactly what it says on the tin.
 * Return: Either 1, for sucess or NULL for failure.
 */
int initialize_stack(SSTAck_t **stack_pointer)
{
	SSTAck_t *s;

	s = malloc(sizeof(SSTAck_t));
	if (s == NULL)
		return (throw_error(COULDNT_MALLOC, 0, ""));

	s->n = 0;
	s->prev = NULL;
	s->next = NULL;

	*stack_pointer = s;

	return (EXIT_SUCCESS);
}

/**
 * free_monty - deallocates whatever memory monty was using
 * @self: double pointer back to Monty
 */
void free_monty(MontyInterpreter_t **self)
{
	SSTAck_t *tmp1 = (*self)->stack;

	free((*self)->operation_tokens);

	while ((*self)->stack)
	{
		tmp1 = ((*self)->stack)->next;
		free((*self)->stack);
		(*self)->stack = tmp1;
	}
	free_command_table((*self)->instructions);

	free(*self);
}

/**
 * tokenize_string - creates string array from line
 * @line: the string we are breaking up
 * @delimiter: the string we are breaking up line with
 * Return: A double pointer which is a list of strings split up
 */
char **tokenize_string(char *line, char *delimiter)
{
	char **holder;
	int i = 0;
	long int length = space_count(line, delimiter);
	char *temp;

	holder = malloc(sizeof(char *) * (length + 1));
	temp = strtok(line, delimiter);
	holder[i] = temp;
	
	while (temp != NULL)
	{
		i++;
		temp = strtok(NULL, delimiter);
		holder[i] = temp;
	}
	return (holder);
}
