#ifndef OOP_MONTY_H
#define OOP_MONTY_H

#include "stringbuff.h"
#include "scriptbuff.h"
#include "command.h"
#include "errors.h"
#include "stack.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>

#define DELIMS " \n\t\a\b"

int execute_script(CommandParser_t **command_parser, char *filename);

#endif
