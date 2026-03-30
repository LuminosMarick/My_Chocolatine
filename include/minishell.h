/*
** EPITECH PROJECT, 2026
** minishell
** File description:
** Made By Ozy
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>
#include <fcntl.h>

#ifndef MYSH_H
    #define MYSH_H

int my_strncmp(char const *s1, char const *s2, int n);
int my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
char *my_strcpy(char *dest, char const *src);
int my_strcmp(char *a, char *b);
char *my_strdup(char *s);
int my_strlen(const char *s);
char *my_strcat(char *dest, char const *src);
char **parse_line(char *line);
char *get_path_env(char **env);
int builtin_cd(char **argv);
int builtin_setenv(char **argv, char **env);
int builtin_unsetenv(char **argv, char **env);
void handle_line(char *line, char **env, int *status);
void execute_command(char **argv, char **env, int *status);
char *find_command(char *cmd, char **env);
char *get_env(char **env, const char *name);
void free_argv(char **argv);
char *my_strchr(char *str, char c);
char *my_strstr(char *str, char *to_find);
int process_line(char *line, char **env, int *status);
void handle_pipe(char *line, char **env, int *status);
void execute_pipe(char *cmd1, char *cmd2, char **env, int *status);
void execute_simple_command(char *line, char **env, int *status);
void redirect_output_flag(char *line, char **env, int *status, int flag);
void redirect_input(char *line, char **env, int *status);

#endif
