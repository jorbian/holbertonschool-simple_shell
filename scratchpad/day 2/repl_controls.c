#include "simple_shell.h"

Control find_repl_control(char *command_arg);
void clear_screen(UserInterface_t **repl);
void terminate_repl(UserInterface_t **repl);
void change_prompt(UserInterface_t **repl);

Control find_repl_control(char *command_arg)
{
	int i;
	REPLControl_t defined_controls[] = {{"exit", terminate_repl},
{"quit", terminate_repl}, {"clear", clear_screen},
{"new_prompt", change_prompt}};

	for (i = 0; defined_controls[i].name; i++)
	{
		if (strcmp(command_arg, defined_controls[i].name) == 0)
			return (defined_controls[i].fp);
	}
	return (NULL);
}

void clear_screen(UserInterface_t **repl)
{
	(void)repl;
	printf("THIS IS SUPPOSED TO CLEAR THE SCREEN...\n");
}

/**
 * terminate_repl - used to end current session
 * @repl: double pointer back to the repl
 */
void terminate_repl(UserInterface_t **repl)
{
	(*repl)->is_active = FALSE;
}

void change_prompt(UserInterface_t **repl)
{
	(void)repl;
	printf("THIS IS SUPPOSED TO CHANGE THE PROMPT...\n");
}
