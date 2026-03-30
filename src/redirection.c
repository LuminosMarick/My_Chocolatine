/*
** EPITECH PROJECT, 2026
** minishell
** File description:
** Made By Ozy
*/

#include "../include/minishell.h"

void redirect_input(char *line, char **env, int *status)
{
    char *cmd;
    char *file;
    int fd;

    cmd = strtok(line, "<");
    file = strtok(NULL, " \t\n");
    fd = open(file, O_RDONLY);
    if (fork() == 0) {
        dup2(fd, 0);
        close(fd);
        execute_simple_command(cmd, env, status);
        exit(1);
    }
    close(fd);
    wait(status);
}

void redirect_output_flag(char *line, char **env, int *status, int flag)
{
    char *cmd;
    char *file;
    int fd;
    pid_t pid;

    cmd = strtok(line, ">");
    file = strtok(NULL, ">");
    if (file)
        file = strtok(file, " \t\n");
    fd = open(file, O_CREAT | O_WRONLY | flag, 0644);
    pid = fork();
    if (pid == 0) {
        dup2(fd, 1);
        close(fd);
        execute_simple_command(cmd, env, status);
        exit(0);
    }
    close(fd);
    wait(NULL);
}
