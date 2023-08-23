#ifndef _SHELL_H_
#define _SHELL_H_

#define BUFFER_SIZE 1024
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <errno.h>
#include <fcntl.h>
#include <limits.h>


extern char **environ;

char *get_line();

int _atoi(char *s);

int display_prompt(void);

char *_getenv(char *name);

int _strncmp(const char *str1, const char *str2, size_t num);

char *_strtok(char *str, const char *delim);

int _strcmp(char *s1, char *s2);

char *_strchr(const char *str, int ch);

char *_strdup(char *str);

char *_strcat(char *dest, char *src);

int _strlen(char *s);

char *_strcpy(char *dest, const char *src);

int exec_command(char *argv[]);

char *find_command_path(char *command);

void display_error_message(char **argv, char *message);

int dis_string(char *str);

int _puterr(char c);

void exit_prompt(char **exit_command, int exit_status);

char *create_env(char *env_name, char *env_value);

void show_env(void);

int set_env(char *name, char *value);

int unset_env(char *var_name);

int check_env(char *str);

int execute_env(char **args);

int _echo(char *args);

char *shell_prompt(ssize_t *file_check);

void free_array_vectors(char *argv[]);

char **command_tokens(char *cmd_input, char **cmd, ssize_t file);

int set_environ(char *args[]);

#endif

