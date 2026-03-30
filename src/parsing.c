/*
** EPITECH PROJECT, 2026
** minishell
** File description:
** Made By Ozy
*/

#include "../include/minishell.h"

char **parse_line(char *line)
{
    char **argv = malloc(sizeof(char *) * 64);
    int i = 0;
    char *token;

    if (!argv)
        return NULL;
    token = strtok(line, " \t\n");
    while (token && i < 63) {
        argv[i] = token;
        token = strtok(NULL, " \t\n");
        i++;
    }
    argv[i] = NULL;
    return argv;
}

void free_argv(char **argv)
{
    if (!argv)
        return;
    free(argv);
}
