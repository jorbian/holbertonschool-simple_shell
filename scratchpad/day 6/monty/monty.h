#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>

#include "include/string_data.h"
#include "include/base_structs.h"

/* MAKE SURE THESE ARE KEPT UPDATED AND MATCH! */
#define NUM_OF_OPS 7
#define NAME_BUFFER_SIZE 5
#define OPCODE_NAMES {"push", "pall", "pint", "pop", "swap", "nop", "add"}
#define FUNCTIONS {push, pall, pint, pop, swap, nop, add}

/* DEFINITIONS OF ERRORS AND THE ERROR HANDLIJG ROUTINE(S) */
#define BAD_INPUT "USAGE: monty file\n"
#define BAD_FILE "Error: Can't open file %s\n"
#define COULDNT_MALLOC "Error: malloc failed\n"
#define BAD_INSTRUCTION "L%d: unknown instruction %s\n"
#define CANT_PUSH "L%d: usage: push integer\n"
#define CANT_PINT "L%d: can't pint, stack empty\n"
#define CANT_POP "L%d: can't pop an empty stack\n"
#define SHORT_STACK "L%d: can't %s, stack too short\n"
#define UNKNOWN "Unknown error\n"

/* BOOLEANS DON'T EXIST IN THIS VERSION OF C */
#define TRUE 1
#define FALSE 0
#define FLAG 2147483647

typedef struct MontyInterpreter_s
{
    char **operation_tokens;
    int line_num; 
    CommandTable_t *instructions;
    SSTAck_t *stack;
    int error_triggered;
} MontyInterpreter_t;

typedef struct ScriptReader_s
{
    StringBuffer_t *line_buffer;
    int line_number;
    int error_triggered;
} ScriptReader_t; 

int initialisation(MontyInterpreter_t **monty, ScriptReader_t **script);
int interpret_script(MontyInterpreter_t **monty, ScriptReader_t **script);

/* SCRIPTREADER METHODS */
int create_script_reader(ScriptReader_t **self);
void free_script_reader(ScriptReader_t **self);
void load_script(ScriptReader_t **self, FILE *source);

/* INTERPRETER METHODS */
int create_monty(MontyInterpreter_t **self);
void free_monty(MontyInterpreter_t **self);

/* OUR ONE ERROR HANDLING ROUTINE */
int throw_error(char *message, int line, char *string);

#endif
