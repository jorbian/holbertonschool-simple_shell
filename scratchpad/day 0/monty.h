#ifndef MONTY_H
#define MONTY_H

#include "stringdata.h"
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
