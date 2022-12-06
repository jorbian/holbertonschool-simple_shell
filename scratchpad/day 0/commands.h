#ifndef COMMAND_H
#define COMMAND_H

#include "stringdata.h"

#define MAX_INPUT_BUFF 255

typedef struct _CommandParser
{
    char *raw_input;
    StringBuffer_t *command_tokens;
    int error_tripped;
} CommandParser_t;

/* METHODS (I.E. FUNCTIONS) FOR CREATING AND USING SCRIPTBUFFER */
int create_command_parser(CommandParser_t **self);
void parse_input(CommandParser_t **self);
void take_input(CommandParser_t **self, char *new_input);
void free_parser(CommandParser_t **self);

#endif
