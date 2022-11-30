#ifndef COMMAND_H
#define COMMAND_H

#include "stringdata.h"

#define MAX_INPUT_BUFF 255
#define DELIMS " \n\t\a\b"

typedef struct _CommandParser
{
    char *raw_input;
    StringBuffer_t *command_tokens;
    int error_tripped;
} CommandParser_t;

/* METHODS (I.E. FUNCTIONS) FOR CREATING AND USING SCRIPTBUFFER */
int create_parser(CommandParser_t **self);
int parse_line(CommandParser_t **self); 
int move_line(CommandParser_t **self, char *new_input);
void free_parser(CommandParser_t **self);

#endif
