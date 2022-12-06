#include "oop_monty.h"

/**
 * execute_script - execute a script instead of launching REPL
 * @filename: the filename fed to main via argv[1]
 * 
 * Return: exit_status -- EXIT_SUCESS or EXIT_FAILURE
 */
int execute_script(CommandParser_t **parser, SSTAck_t **stack, char *file)
{
    int exit_status = 0;
    ScriptBuffer_t *script_buffer = NULL;

    (void)parser;

    script_buffer = malloc(sizeof(ScriptBuffer_t));
    if (script_buffer == NULL)
        return (throw_error(COULDNT_MALLOC, 0, ""));
    load_script_buffer(&script_buffer, file);

    free_script_buffer(&script_buffer);

    return (exit_status);
}

/**
 * load_script_buffer - read the contents of a file line by line into buffer
 * @self: double pointer back to the script buffer
 * @filename: name of the file to be loaded.
*/
void load_script_buffer(ScriptBuffer_t **self, char *file_name)
{
    FILE *file_pointer;
    char *new_line = NULL;
    size_t size_of_line;
    LineBuffer_t *line_buffer = (*self)->curr_line;

    file_pointer = fopen(file_name, "r");
    if (file_pointer == NULL)
    {
        (*self)->error_tripped = 1;
        return;
    }
    while ((getline(&new_line, &size_of_line, file_pointer) != EOF))
        add_to_end(&line_buffer, new_line);

    fclose(file_pointer);
}
