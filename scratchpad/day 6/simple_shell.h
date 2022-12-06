#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "include/stringdata.h"
#include "include/toplevelstructs.h"

#define FALSE 0
#define TRUE 1
#define MAX_INPUT 255
#define MAX_PIPE 1023

/* TWO MAIN CONTROL PATHS WE CAN TAKE */
void open_repl(SimpleShell_t **shell, UserInterface_t **repl);
void interpret_script(SimpleShell_t **shell, ScriptReader_t **script);

/* SHELL (i.e. INTERPRETER) RELATED METHODS */
int create_simple_shell(SimpleShell_t **self);
void free_simple_shell(SimpleShell_t **self);

/* UI/REPL RELATED METHODS */
int create_ui(UserInterface_t **self);
void get_input(UserInterface_t **self);
void free_ui(UserInterface_t **self);

/* SCRIPTREADER METHODS */
int create_script_reader(ScriptReader_t **self);
void load_script(ScriptReader_t **self, FILE *source);
void list_script(ScriptReader_t **self);
void clear_script(ScriptReader_t **self);
void free_script_reader(ScriptReader_t **self);

#endif
