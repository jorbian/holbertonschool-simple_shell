#ifndef PARSER_H
#define PARSER_H

#include "monty.h"
#include "stringdata.h"

#define MAX_INPUT_BUFF 255

/**
 * struct CommandTable_s - Node of a hash table
 *
 * @key: name of the command
 * @value: function pointer to what it invokes
 * @next: A pointer to the next node of the List
 */
typedef struct CommandNode_s
{
    char *key;
    void (*f)(stack_t **stack_pointer, unsigned int line_number);
    struct CommandNode_s *next;
} CommandNode_t;

/**
 * struct CommandTable_s - Hash table data structure
 *
 * @size: The size of the array
 * @array: An array of size @size
 * Each cell of this array is a pointer to the first node of a linked list,
 * because we want our HashTable to use a Chaining collision handling
 */
typedef struct CommandTable_s
{
     unsigned long int size;
     CommandNode_t **array;
} CommandTable_t;

/**
 * struct CommandParser - Collections of data needed to parse commands.
 * 
 * @raw_input: place to put lines of input -- from either a script or the REPL
 * @error_tripped: if an error has been tripped, 1 for 'Yes' or 0 for 'No'
 * @tokens: doubly linked list of parsed input
 * @table: hash table used to get function pointers to commands.
*/
typedef struct _CommandParser
{
    char *raw_input;
    int error_tripped;
    StringBuffer_t *tokens;
    CommandTable_t *table;
} CommandParser_t;

/** TYPE ALIAS FOR THE FUNCTION POINTERS ON HASH TABLE */
typedef void (*Command)(stack_t **stack_pointer, unsigned int line_number);

/** FUNCTIONS USED TO BUILD AND MANAGE THE COMMAND LOOKUP TABLE */
int create_command_table(CommandTable_t **table);
CommandTable_t *allocate_memory_for_table(unsigned long int size);
Command get_command(const CommandTable_t *table, const char *key);
int set_command(CommandTable_t *table, const char *key, Command func);
unsigned long int hash_djb2(const unsigned char *str);
unsigned long int key_index(const unsigned char *key, unsigned long int size);
void free_command_table(CommandTable_t *table);

/* METHODS (I.E. FUNCTIONS) FOR CREATING AND USING SCRIPTBUFFER */
void create_command_parser(CommandParser_t **self);
void parse_input(CommandParser_t **self);
void take_input(CommandParser_t **self, char *new_input);
void free_parser(CommandParser_t **self);

#endif
