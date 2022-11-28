#ifndef STRINGBUFF_H
#define STRINGBUFF_H

/**
 * struct StringBuffer_s - Doubly linked list of strings 
 * @string: string store in buffer (either a whole line or command token)
 * @prev_line: points to previous line.
 * @next_line: points to next line.
 * 
 * Description: doubly linked list used to represent lines of file or
 * command tokens parsed from a line to be nested inside the script and 
 * command buffers respectiely.
 */
typedef struct StringBuffer_s
{
		char *contents;
		struct StringBuffer_s *next;
		struct StringBuffer_s *prev;
} StringBuffer_t;

typedef struct StringBuffer_s LineBuffer_t;
typedef struct StringBuffer_s TokenBuffer_t;

StringBuffer_t *add_string(StringBuffer_t **top_node, const char *new_str);
StringBuffer_t *add_to_end(StringBuffer_t **top_node, const char *new_str);
void check_stringbuff(const StringBuffer_t *current_node);
void free_stringbuff(StringBuffer_t *current_node);

#endif
