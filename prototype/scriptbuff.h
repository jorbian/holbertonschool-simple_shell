#ifndef SCRIPTBUFF_H
#define SCRIPTBUFF_H

#include "stringbuff.h"

/**
 * struct ScriptBuffer_s - centralized location all we need to read script
 * @curr_line: pointer to the current line as LineBuffer_s
 * @curr_line_num: line number of current line being pointed to
 * @load: load the contents of a file into the buffer
 * @list: list the (remaining) contents of buffer
 * @clear: clear the contents of buffer to start over (PLACEHOLDER)
 * @free: deallocate memory for the buffer and its members
 * @next_line: move to the next line.
 *
 * Description: doubly linked list nested inside ScriptBuffer --
 * whose function is to contain pointers to de faccto object methods.
 */
typedef struct _ScriptBuffer
{
		struct LineBuffer_s *curr_line;
		int curr_line_num;
		int error_tripped;
		void (*load)(struct _ScriptBuffer **, char *);
		void (*list)(struct _ScriptBuffer **);
		void (*clear)(struct _ScriptBuffer **);
		void (*free)(struct _ScriptBuffer **);
		void (*next_line)(struct _ScriptBuffer **);
} ScriptBuffer_t;

void create_script_buffer(ScriptBuffer_t **self);
void load_script_buffer(ScriptBuffer_t **self, char *file_name);
void list_script_buffer(ScriptBuffer_t **self);
void clear_script_buffer(ScriptBuffer_t **self);
void free_script_buffer(ScriptBuffer_t **self);
void move_2_next_line(ScriptBuffer_t **self);

#endif
