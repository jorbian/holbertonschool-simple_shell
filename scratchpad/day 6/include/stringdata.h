#ifndef STRINGDATA_H
#define STRINGDATA_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * struct StringBuffer_s - Doubly linked list of strings 
 * @string: string store in buffer (either a whole line or command token)
 * @prev_line: points to previous line.
 * @next_line: points to next line.
 * 
 * Description: doubly linked list used to represent lines of file or
 * command tokens parsed from a line.
 */
typedef struct StringBuffer_t
{
		char *contents;
		struct StringBuffer_t *next;
		struct StringBuffer_t *prev;
} StringBuffer_t;

/**
 * struct ScriptBuffer_s - centralized location all we need to read script
 * @curr_line: pointer to the current line as LineBuffer_s
 * @curr_line_num: line number of current line being pointed to
 *
 * Description: doubly linked list nested inside ScriptBuffer --
 * whose function is to contain pointers to de faccto object methods.
 */
typedef struct ScriptReader_s
{
		struct StringBuffer_t *line_buffer;
		int reg_error;
        int fatal_error;
} ScriptReader_t;

/* FUNCTIONS USED TO CREATE AND MANAGE STRING BUFFERS, LINE, TOK 'AND OTHER' */
StringBuffer_t *add_string(StringBuffer_t **top_node, const char *new_str);
StringBuffer_t *add_to_end(StringBuffer_t **top_node, const char *new_str);
char *pop_string(StringBuffer_t **top_node);
void check(const StringBuffer_t *current_node);
void free_stringbuff(StringBuffer_t *current_node);

/* MISC STRING FUNCTIONS */
int only_spaces(char *string);
int space_count(char *str, char *delimiter);
char **tokenize_string(char *line, char *delimiter);

#endif
