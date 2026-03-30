/*
** EPITECH PROJECT, 2026
** minishell
** File description:
** Made By Ozy
*/

#include "../include/minishell.h"
#include <signal.h>

void display_prompt(void)
{
    write(1, "|->", 3);
    my_putchar('[');
    my_putstr("\033[1;32mOzyShell\033[0m");
    my_putchar(']');
    my_putchar('=');
    my_putchar('[');
    my_putstr("\033[1;36mprod-@-G-PSU-200\033[0m");
    my_putchar(']');
    write(1, "->$> ", 5);
}

void handle_sigint(int sig)
{
    (void)sig;
    write(1, "\n", 1);
    display_prompt();
}

void shell_loop(char **env)
{
    char *line = NULL;
    size_t size = 0;
    int status = 0;

    while (1) {
        if (isatty(0))
            display_prompt();
        if (getline(&line, &size, stdin) == -1) {
            free(line);
            exit(status);
        }
        handle_line(line, env, &status);
    }
}

int main(int ac, char **av, char **env)
{
    (void)ac;
    (void)av;
    signal(SIGINT, handle_sigint);
    shell_loop(env);
    return 0;
}
