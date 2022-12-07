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
 * struct _SimpleShell - information representing current state of shell
 * @line_num: current line number of script
 * @exit_status: EXIT_SUCCESS (0) or EXIT_FAILURE (!)
 * @error_status: TRUE (1) OR FALSE (0) -- may or may not trigger exit
 * @is_active: TRUE (1) OR FALSE (0) -- if REPL loop still open
 * @path_variable: path variable inherited from environment as string array
 * @enviornment: the enviornmental variables.
 * @builtin: function pointer to a builtin command (if any)
 * @os_command_path: path to executable file to invoke (if any)
 * @command_args: arguments parsed from last line of input
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct _SimpleShell
{
	int line_num;
	int exit_status;
	int error_status;
	int is_active;
	char **path_variable;
	char **enviornment;
	void (*builtin)(struct _SimpleShell **);
	char *os_command_path;
	char **command_args;
} SimpleShell_t;

/**
 * struct BuiltInCommand_s - information to build table of built in commands
 * @name: name of the command
 * @exec: function pointer to function which executes command
 */
typedef struct BuiltInCommand_s
{
	char *name;
	void (*exec)(SimpleShell_t **self);
} BuiltInCommand_t;

void launch_repl(SimpleShell_t **shell);
void read_script(SimpleShell_t **shell);

int create_shell(SimpleShell_t **self, char **envp);
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
char *_getenv(char **envp, char *key);

char *find_command_path(SimpleShell_t **self);
char *create_test_path(char *dir_path, char *command);
void create_new_process(SimpleShell_t **shell);

void errors(char *token, char *argument);

#endif
