#ifndef COMMAND_H
#define COMMAND_H

#include "scriptbuff.h"

#define MAX_INPUT_BUFF 255
#define HISTORY_SIZE 2
#define PREV 0
#define CURR 1

typedef struct _CommandParser
{
    char *raw_input;
    TokenBuffer_t *command_tokens;
    int *history_index;
    int error_tripped;
    void (*parse)(struct _CommandParser **);
    void (*take)(struct _CommandParser **, char *);
    void (*free_self)(struct _CommandParser **);
} CommandParser_t;

int create_command_parser(CommandParser_t **self);

void parse_input(CommandParser_t **self);
void take_input(CommandParser_t **self, char *new_input);
void free_parser(CommandParser_t **self);

#endif
