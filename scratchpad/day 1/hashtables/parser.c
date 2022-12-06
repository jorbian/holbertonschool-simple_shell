#include "parser.h"

/**
 * create_command_parser - exactly what it says on the tin
 * @self: double pointer to the command parser itself
 */
void create_command_parser(CommandParser_t **self)
{
	*self = malloc(sizeof(CommandParser_t));
    if (*self == NULL)
        return;

    (*self)->error_tripped = 0;

	(*self)->raw_input = malloc(sizeof(char) * MAX_INPUT_BUFF);
	if ((*self)->raw_input == NULL)
		(*self)->error_tripped = EXIT_FAILURE;

	(*self)->tokens = NULL;
    (*self)->table = NULL;

    (*self)->error_tripped = create_command_table(&((*self)->table));
}

/**
 * take_input - take a new line of input to be parsed
 * @self: double pointer to the command parser itself
 * @new_input: the new line of input as one string
 */
void take_input(CommandParser_t **self, char *new_input)
{
	if (((*self)->raw_input) == NULL)
	{
		(*self)->raw_input = malloc(sizeof(char) * MAX_INPUT_BUFF);
		if ((*self)->raw_input == NULL)
			return;
	}
	snprintf(((*self)->raw_input), MAX_INPUT_BUFF, "%s", new_input);
}

/**
 * parse_input - parse the line of raw input currently in parser
 * @self: double pointer to the command parser itself
*/
void parse_input(CommandParser_t **self)
{
	char *token;
	char *save_pointer = (*self)->raw_input;

	while ((token = strtok_r(save_pointer, DELIMS, &save_pointer)))
		add_to_end(&((*self)->tokens), token);
}

/**
 * free_parser - free whatever memory that was allocated for the parser
 * and its various members.
 * @self: double pointer to the command parser itself
*/
void free_parser(CommandParser_t **self)
{
	if ((*self)->raw_input)
		free((*self)->raw_input);
	if ((*self)->tokens)
		free_stringbuff((*self)->tokens);
    free_command_table((*self)->table);
	free(*self);
}
