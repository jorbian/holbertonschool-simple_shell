#include "stringdata.h"

/**
* create_script_buffer - the main purpose of this funciton is to set the
* relevant object methods in place
* @self: double pointer back to the script buffer
*/
void create_buffer(ScriptBuffer_t **self)
{
    *self = malloc(sizeof(ScriptBuffer_t));
    if (*self == NULL)
        return; 
    (*self)->curr_line = NULL;
    (*self)->curr_line_num = 0;
    (*self)->error_tripped = EXIT_SUCCESS;
}

/**
 * clear_script_buffer - placeholder function for when I can figure out how
 * to make it so you can load different files in interactive REPL mode
 * @self: double pointer back to the script buffer
*/
void clear_script(ScriptBuffer_t **self)
{
    (void)self;
}

/**
 * move_2_next_line - advance one line forward through script
 * @self: double pointer back to the script buffer
*/
void next_line(ScriptBuffer_t **self)
{
    (void)self; 
}

/**
 * free_script_buffer - deallocate any and all memory used by script buffer.
 * @self: double pointer back to the script buffer
*/
void free_buffer(ScriptBuffer_t **self)
{
    if ((*self)->curr_line)
        free_stringbuff((*self)->curr_line);
    free(self);
}

void list_script(ScriptBuffer_t **self)
{
    check((*self)->curr_line);
}

/**
 * load_script_buffer - read the contents of a file line by line into buffer
 * @self: double pointer back to the script buffer
 * @filename: name of the file to be loaded.
*/
void load_script(ScriptBuffer_t **self, char *file_name)
{
    FILE *file_pointer;
    char *new_line = NULL;
    size_t size_of_line;
    int error_status = EXIT_SUCCESS;

    StringBuffer_t *line_buffer = (*self)->curr_line;

    file_pointer = fopen(file_name, "r");
    error_status = (file_pointer == NULL);
 
    if (error_status == EXIT_SUCCESS)
    {
        while ((getline(&new_line, &size_of_line, file_pointer) != EOF))
        {
            line_buffer = add_to_end(&line_buffer, new_line);
            error_status = (new_line == NULL);
        }

        fclose(file_pointer);
    }
    (*self)->error_tripped = error_status;
}

void free_script(ScriptBuffer_t **self)
{
    if ((*self)->curr_line)
        free_stringbuff((*self)->curr_line);
    free(*self);
}
