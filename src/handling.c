/*
** EPITECH PROJECT, 2026
** minishell2
** File description:
** Made By Ozy
*/

#include "../include/minishell.h"

int print_sentence(void)
{
    printf("Life, the universe and everything\n");
    return 42;
}

void handle_line(char *line, char **env, int *status)
{
    char **argv;

    if (process_line(line, env, status))
        return;
    argv = parse_line(line);
    if (!argv || !argv[0]) {
        free_argv(argv);
        return;
    }
    if (my_strcmp(argv[0], "42") == 0) {
        print_sentence();
    }
    if (my_strcmp(argv[0], "exit") == 0) {
        free_argv(argv);
        exit(*status);
    }
    if (my_strcmp(argv[0], "cd") == 0)
        *status = builtin_cd(argv);
    else
        execute_command(argv, env, status);
    free_argv(argv);
}

void execute_simple_command(char *line, char **env, int *status)
{
    char **argv;

    argv = parse_line(line);
    if (!argv || !argv[0]) {
        free_argv(argv);
        return;
    }
    if (my_strcmp(argv[0], "exit") == 0) {
        free_argv(argv);
        exit(*status);
    }
    if (my_strcmp(argv[0], "cd") == 0)
        *status = builtin_cd(argv);
    else
        execute_command(argv, env, status);
    free_argv(argv);
}

int handle_semicolon(char *line, char **env, int *status)
{
    char *cmd;
    char *saveptr;

    cmd = strtok_r(line, ";", &saveptr);
    while (cmd) {
        if (cmd[0] != '\0')
            handle_line(cmd, env, status);
        cmd = strtok_r(NULL, ";", &saveptr);
    }
    return 1;
}

int process_line(char *line, char **env, int *status)
{
    if (my_strchr(line, ';'))
        return handle_semicolon(line, env, status);
    if (my_strchr(line, '|')) {
        handle_pipe(line, env, status);
        return 1;
    }
    if (my_strchr(line, '<')) {
        redirect_input(line, env, status);
        return 1;
    }
    if (my_strstr(line, ">>")) {
        redirect_output_flag(line, env, status, O_APPEND);
        return 1;
    }
    if (my_strchr(line, '>')) {
        redirect_output_flag(line, env, status, O_TRUNC);
        return 1;
    }
    return 0;
}
