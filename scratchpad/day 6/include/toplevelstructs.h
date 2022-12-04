#ifndef TOPLEVELSTRUCTS_H
#define TOPLEVELSTRUCTS_H

#include "stringdata.h"

#define PROMPT_LEN 6
#define PROMPT "($) " 

/**
 * struct SimpleShell_s - the core interpreter
 * @args: command arguments parsed from most recent input
 * @history: every line of input that has been read so far
 * @commands: hash table containing function pointers to match commands
 * @reg_error: whether or not a regular error has occured (TRUE or FALSE)
 * @fatal_error: whether or not a fatal error has occured (TRUE or FALSE)
 */
typedef struct SimpleShell_s
{
    char **args;
    StringBuffer_t *history;
    int reg_error;
    int fatal_error;
} SimpleShell_t;

/**
 * struct UserInterface_s - data structure to control interpreter interactively
 * @is_active: whether or not the REPL is still active (TRUE or FALSE)
 * @prompt: the prompt that gets displayed to the user
 * @raw_input: last input taken from the user as string
 * @repl_controls: array of repl control structs
 * @reg_error: whether or not a regular error has occured (TRUE or FALSE)
 * @fatal_error: whether or not a fatal error has occured (TRUE or FALSE)
 */
typedef struct UserInterface_s
{
    int is_active;
    char prompt[PROMPT_LEN];
    char *raw_input;
    int reg_error;
    int fatal_error;
} UserInterface_t; 

/**
 * struct CommandTable_s - Node of a hash table
 * @name: name of the command
 * @fp: function pointer to what it invokes
 * @next: A pointer to the next node of the List
 */
typedef struct CommandNode_s
{
    char *name;
    void (*fp)(SimpleShell_t **shell);
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
 * struct REPLControl_s - repl specific command for testing purposes
 * @name: the name of the command
 * @fp: function pointer to what it's supposed to do
 * 
 * Description: PROBABLY FOR TESTING PURPOSES ONLY
 */
typedef struct REPLControl_s
{
    char *name;
    void (*fp)(UserInterface_t **repl);
} REPLControl_t;

/** TYPE ALIASES FOR FP TREES */
typedef void (*Command)(SimpleShell_t **shell);
typedef void (*Control)(UserInterface_t **repl); 

/* FUNCTIONS USED TO BUILD AND MANAGE THE COMMAND LOOKUP TABLE */
int create_command_table(CommandTable_t **table);
Command get_command(const CommandTable_t *table, const char *key);
int set_command(CommandTable_t *table, const char *key, Command func);
unsigned long int hash_djb2(const unsigned char *str);
unsigned long int key_index(const unsigned char *key, unsigned long int size);
void free_command_table(CommandTable_t *table);

#endif 
