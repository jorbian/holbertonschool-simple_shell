#include "simple_shell.h"

int main()
{
	SimpleShell_t *shell = NULL;

	create_shell(&shell);

	parse_line(&shell, "asdf");
	parse_line(&shell, "ls");

	free_shell(&shell);
	return (0);
}

/**
 * create_shell - allocate memory for the simple shell and set inotal values
 * @self: double pointer back to the simple shell
 *
 * Return: Whether or not the shell was sucessfully created.
 */
int create_shell(SimpleShell_t **self)
{
	*self = malloc(sizeof(SimpleShell_t));
	if (self == NULL)
		return (EXIT_FAILURE);

	((*self)->is_active) = TRUE;
	((*self)->error_status) = FALSE;
	(*self)->path_variable = split_string(getenv("PATH"), ":");

	snprintf((*self)->username, NAME_BUFF_SIZE, "%s", getenv("USER"));
	snprintf((*self)->curr_working_dir, NAME_BUFF_SIZE, "%s", getenv("PWD"));

	(*self)->builtin = NULL;
	(*self)->command_args = NULL;

	return (EXIT_SUCCESS);
}

/**
 * parse_line - parses an individual line taken from a script or the REPL
 * @self: double pointer back to the simple shell
 * @new_line: the new line to be parsed
 *
 * Description: WILL REQUIRE SIGNIFICANT OVERHALL TO SUPPORT PIPES!!!
*/
void parse_line(SimpleShell_t **self, char *new_line)
{
	int is_valid_command = 0;

	(*self)->command_args = split_string(new_line, " ");

	(*self)->builtin = get_builtin((*self)->command_args[0]);

	if ((*self)->builtin != NULL)
	{
		(*self)->builtin(self);
		return;
	}

	is_valid_command = validate_command(self);

	if (is_valid_command)
		printf("%s was a valid command.", (*self)->command_args[0]);
	else
		printf("%s WAS NOT a valid command.", (*self)->command_args[0]);
}

/**
 * free_shell - deallocates memory for the interpreter and its properties
 * @self: double pointer back to the simple shell
 */
void free_shell(SimpleShell_t **self)
{
	free((*self)->path_variable);
	free((*self)->command_args);
	free(*self);
}
