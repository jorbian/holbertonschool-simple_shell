#ifndef STRING_DATA_H
#define STRING_DATA_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * struct StringBuffer_s - Doubly linked list of strings 
 * @string: string store in buffer (either a whole line or command token)
 * @prev: points to previous line.
 * @next: points to next line.
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
