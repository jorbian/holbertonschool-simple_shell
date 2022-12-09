#ifndef TEST_SHELL_H
#define TEST_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_LINE 80 /* 80 chars per line, per command, should be enough. */
#define MAX_ARGS 10 /* 10 args per command, should be enough. */

#define TRUE 1
#define FALSE 0

#define READ 0
#define WRITE 1

#define STDIN 0
#define STDOUT 1
#define STDERR 2

#define MAX_HISTORY 10
#define MAX_PIPES 10
#define MAX_JOBS 10
#define MAX_JOB_NAME 20
#define MAX_JOB_ARGS 10
#define MAX_PATH 100

typedef struct {
    char *args[MAX_JOB_ARGS];
    int num_args;
    int background;
    int input_redir;
    int output_redir;
    int error_redir;
    char *input_file;
    char *output_file;
    char *error_file;
    int pipe;
    int pipe_index;
    int pipe_fd[2];
    int pipe_read;
    int pipe_write;
    int pipe_read_index;
    int pipe_write_index;
    int pipe_read_fd[2];
    int pipe_write_fd[2];
    int job_id;
    char job_name[MAX_JOB_NAME];
    int job_status;
    int job_pid;
} job_t;

int parse_command(char *cmd, job_t *job);
void print_jobs(job_t *jobs, int num_jobs);
void print_history(char *history[], int num_history);
char *get_history(char *history[], int num_history, int index);
void add_history(char *history[], int *num_history, char *cmd);
void print_prompt();
void clear_screen();
char *get_command(char *cmd, int size);
void print_error(char *msg);
void print_error2(char *msg, char *arg);
int is_empty(char *cmd);
int is_comment(char *cmd);
int is_history(char *cmd);
char *trim(char *cmd);
char *get_path(char *path, char *cmd);
char *buffer_to_string(char *buffer, int size);
char *string_parse(char *string, char *delim);

#endif 