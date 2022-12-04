#include "monty.h"

/**
 * create_script_reader - initalise the ScriptReader
 * @self: double pointer back to SR
 * 
 * Return: Whether or not there was a problem
 *         1 for Yes -- 0 for No -- 
 */
int create_script_reader(ScriptReader_t **self)
{
    *self = malloc(sizeof(ScriptReader_t));
    if (*self == NULL)
        return (throw_error(COULDNT_MALLOC, 0, ""));

    (*self)->line_buffer = NULL;
    (*self)->line_buffer = malloc(sizeof(StringBuffer_t));
    if ((*self)->line_buffer == NULL)
        return (throw_error(COULDNT_MALLOC, 0, ""));

    (*self)->line_number = 0;
    (*self)->error_triggered = FALSE;

    return (EXIT_SUCCESS);
}

/**
 * free_script_reader - deallocate whatever memory from SR
 * @self: double pointer back to SR
 */
void free_script_reader(ScriptReader_t **self)
{
    free_stringbuff((*self)->line_buffer);
    free(*self);
}

/**
 * load_script - read the contents of a file line by line into buffer
 * @self: double pointer back to the script buffer
 * @source: pointer to wherever the script is coming from
*/
void load_script(ScriptReader_t **self, FILE *source)
{
    char *new_line = NULL;
    size_t size_of_line;
    StringBuffer_t *buffer = (*self)->line_buffer;

    if (source == NULL)
    {
        (*self)->error_triggered = 1;
        return;
    }
    while ((getline(&new_line, &size_of_line, source) != EOF))
        add_to_end(&buffer, new_line);
        
    pop_string(&(*self)->line_buffer);
}
