#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#define TRUE 1
#define FALSE 0

#define NAME_BUFF_SIZE 127
#define WORKING_DIR_BUFF 255
#define PATH_MAX 4096

/**
 * struct SimpleShell_s - information representing current state of shell
 * @exit_status: EXIT_SUCCESS (0) or EXIT_FAILURE (!)
 * @error_status: TRUE (1) OR FALSE (0) -- may or may not trigger immediate exit
 * @path_variable: path variable inherited from environment as string array
 * @username: username inherited from environment
 * @curr_working_dir: working directory (initally inherit from enviornment)
 * @command_args: arguments parsed from last line of input
 * 
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct _SimpleShell
{
    int error_status;
    int is_active;
    char **path_variable;
    char username[NAME_BUFF_SIZE];
    char curr_working_dir[WORKING_DIR_BUFF];
    void (*builtin)(struct _SimpleShell **);
    char **command_args;
    int arg_count;
} SimpleShell_t;

/**
 * struct SimpleShell_s - information to build table of built in commands
 * @name: name of the command
 * @exec: function pointer to function which executes command
 */
typedef struct BuiltInCommand_s
{
    char *name;
    void (*exec)(SimpleShell_t **self);
} BuiltInCommand_t;

int create_shell(SimpleShell_t **self);
int is_command(SimpleShell_t **self, char *command);
void parse_line(SimpleShell_t **self, char *new_line);
void free_shell(SimpleShell_t **self);

char *take_input(void);
int is_only_spaces(char *string);
int num_of_spaces(char *string, char *delimiter);
char **split_string(char *string_to_split, char *delimiter);

void (*get_builtin(char *command))(SimpleShell_t **);
void clear_screen(SimpleShell_t **self);
void quit_repl(SimpleShell_t **self);
void print_env_variables(SimpleShell_t **self);

int validate_command(SimpleShell_t **self);
int contains_slash(char *command);
char *find_local_path(char *string);
char *expand_path(char *string);

void errors(char *token, char *argument);

#endif
