/*
** EPITECH PROJECT, 2026
** minishell
** File description:
** Made By Ozy
*/

#include "../include/minishell.h"

int split_pipe(char *line, char **cmds)
{
    int i = 0;
    char *token = strtok(line, "|");

    while (token && i < 63) {
        cmds[i] = token;
        token = strtok(NULL, "|");
        i++;
    }
    cmds[i] = NULL;
    return i;
}

void exec_pipe_child(char *cmd, char **env, int prev_fd, int pipefd[2])
{
    if (prev_fd != -1) {
        dup2(prev_fd, 0);
        close(prev_fd);
    }
    if (pipefd[1] != -1) {
        dup2(pipefd[1], 1);
        close(pipefd[0]);
        close(pipefd[1]);
    }
    execute_simple_command(cmd, env, NULL);
    exit(0);
}

void update_parent_fd(int *prev_fd, int pipefd[2])
{
    if (*prev_fd != -1)
        close(*prev_fd);
    if (pipefd[0] != -1) {
        close(pipefd[1]);
        *prev_fd = pipefd[0];
    }
}

void handle_pipe(char *line, char **env, int *status)
{
    char *cmds[64];
    int nb_cmds;
    int pipefd[2];
    int prev_fd = -1;
    pid_t pid;

    nb_cmds = split_pipe(line, cmds);
    for (int i = 0; i < nb_cmds; i++) {
        pipefd[0] = -1;
        pipefd[1] = -1;
        if (i < nb_cmds - 1)
            pipe(pipefd);
        pid = fork();
        if (pid == 0)
            exec_pipe_child(cmds[i], env, prev_fd, pipefd);
        update_parent_fd(&prev_fd, pipefd);
    }
    while (wait(NULL) > 0);
}
