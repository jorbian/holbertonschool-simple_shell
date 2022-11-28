#include "oop_monty.h"

/**
 * create_command_parser - exactly what it says on the tin
 * @self: double pointer to the command parser itself
 */
int create_command_parser(CommandParser_t **self)
{
	(*self)->raw_input = malloc(sizeof(char) * MAX_INPUT_BUFF);
	if ((*self)->raw_input == NULL)
		return (throw_error(COULDNT_MALLOC, 0, ""));

	(*self)->command_tokens = NULL;

	(*self)->history_index = malloc(sizeof(int) * HISTORY_SIZE);
	if ((*self)->history_index == NULL)
		return (throw_error(COULDNT_MALLOC, 0, ""));

	(*self)->history_index[PREV] = 0;
	(*self)->history_index[CURR] = 0;

	(*self)->error_tripped = 0;

	(*self)->parse = parse_input;
	(*self)->take = take_input;
	(*self)->free_self = free_parser;

	return (EXIT_SUCCESS);
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
	int num_of_tokens = 0;
	int prev_tokens = (*self)->history_index[CURR];

	while ((token = strtok_r(save_pointer, DELIMS, &save_pointer)))
	{
		num_of_tokens++;
		add_to_end(&((*self)->command_tokens), token);
	}
	(*self)->history_index[PREV] = prev_tokens;
	(*self)->history_index[CURR] = prev_tokens + num_of_tokens;
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
	if ((*self)->command_tokens)
		free_stringbuff((*self)->command_tokens);
	if ((*self)->history_index)
		free((*self)->history_index);
	free(*self);
}
