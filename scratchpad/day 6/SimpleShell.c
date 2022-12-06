#include "simple_shell.h"

/**
 * create_simple_shell - create the command interpreter
 * @self: double pointer back to shell
 *
 * Description: Allocates memory for interpreter and its nested structs.
 * Return: If there was a problem creating interpreter.
 */
int create_simple_shell(SimpleShell_t **self)
{
    *self = malloc(sizeof(SimpleShell_t));
    if (*self == NULL)
        return (EXIT_FAILURE);

    (*self)->history = malloc(sizeof(StringBuffer_t));
    if ((*self)->history == NULL)
        return (EXIT_FAILURE);

    return (EXIT_SUCCESS);
}

/**
 * process_new_input - take a new line of input from REPL or ScriptReader
 * @self: double pointer back to the shell
 * @new_input: the new line of input to be process
 *
 * Description: Input is first stored at next line of history and then
 *              tokenized and added into args for use invoking command(s)
*/
void process_new_input(SimpleShell_t **self, char *new_input)
{
    add(&((*self)->history), new_input);
}

void free_simple_shell(SimpleShell_t **self)
{
    if ((*self)->args != NULL)
        free((*self)->args);
    if ((*self)->history != NULL)
        free_stringbuff((*self)->history);
    free(*self);
}
