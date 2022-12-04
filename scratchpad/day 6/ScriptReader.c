#include "simple_shell.h"

/**
 * create_script_reader - allocate memory for an initalize ScriptReader
 * @self: double pointer back to the ScriptReader
 */
int create_script_reader(ScriptReader_t **self)
{
    *self = malloc(sizeof(ScriptReader_t));
    if (*self == NULL)
        return (EXIT_FAILURE);

    (*self)->line_buffer = NULL;
    (*self)->line_buffer = malloc(sizeof(StringBuffer_t));
    if ((*self)->line_buffer == NULL)
        return (EXIT_FAILURE);

    (*self)->fatal_error = 0;
    (*self)->reg_error = 0;
}

/**
 * free_script_reader - deallocate whatever memory ScriptReader was using
 * @self: doubple pointer back to the ScriptReader
 */
void free_script_reader(ScriptReader_t **self)
{
    free_stringbuff((*self)->line_buffer);
    free(*self);
}