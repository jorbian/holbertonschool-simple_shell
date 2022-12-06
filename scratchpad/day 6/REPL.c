#include "simple_shell.h"

int create_ui(UserInterface_t **self)
{
	*self = malloc(sizeof(UserInterface_t));
	if (*self == NULL)
		return (EXIT_FAILURE);

	snprintf((*self)->prompt, PROMPT_LEN, "%s", PROMPT);

	(*self)->raw_input = malloc(sizeof(char) * MAX_INPUT);
	if ((*self)->raw_input)
		return (EXIT_FAILURE);

	return (EXIT_SUCCESS);
}

void free_ui(UserInterface_t **self)
{
	if ((*self)->raw_input)
		free((*self)->raw_input);
	free(*self);
}

/**
 * get_input - Receives input and makes it safe to process
 * @self: double pointer back to the UI
 */
void get_input(UserInterface_t **self)
{
	char *temp_buff;
	size_t n = 1;
	ssize_t check;
	char new_line[] = {'\n', '\0'};

	temp_buff = malloc(sizeof(char) * 1);

	check = (getline(&temp_buff, &n, stdin));
	if (((*self)->fatal_error = (check == -1)))
	{
		free(temp_buff);
		return;
	}
	if (temp_buff[0] == '\n' && temp_buff[1] == '\0')
		;
	else
	{
		temp_buff = strtok(temp_buff, new_line);
		if ((only_spaces(temp_buff)))
		{
			temp_buff[0] = '\n';
			temp_buff[1] = '\0';
		}
	}
	snprintf((*self)->raw_input, MAX_INPUT, "%s", temp_buff);

	free(temp_buff);
}


