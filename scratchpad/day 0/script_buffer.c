#include "oop_monty.h"

/**
* create_script_buffer - the main purpose of this funciton is to set the
* relevant object methods in place
* @self: double pointer back to the script buffer
*/
void create_script_buffer(ScriptBuffer_t **self)
{
    (*self)->curr_line = NULL;
    (*self)->curr_line_num = 0;
    (*self)->error_tripped = 0;
	(*self)->load = load_script_buffer;
	(*self)->list = list_script_buffer;
	(*self)->clear = clear_script_buffer;
    (*self)->free = free_script_buffer;
    (*self)->next_line = move_2_next_line;
}

/**
 * clear_script_buffer - placeholder function for when I can figure out how
 * to make it so you can load different files in interactive REPL mode
 * @self: double pointer back to the script buffer
*/
void clear_script_buffer(ScriptBuffer_t **self)
{
    (void)self;
}

/**
 * move_2_next_line - advance one line forward through script
 * @self: double pointer back to the script buffer
*/
void move_2_next_line(ScriptBuffer_t **self)
{
    (void)self; 
}

/**
 * free_script_buffer - deallocate any and all memory used by script buffer.
 * @self: double pointer back to the script buffer
*/
void free_script_buffer(ScriptBuffer_t **self)
{
    if ((*self)->curr_line)
        free_stringbuff((*self)->curr_line);
    free(self);
}

void list_script_buffer(ScriptBuffer_t **self)
{
    (void)self;
}
