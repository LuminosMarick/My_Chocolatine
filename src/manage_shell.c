/*
** EPITECH PROJECT, 2026
** minishell
** File description:
** Made By Ozy
*/

#include "../include/minishell.h"
#include <errno.h>
#include <sys/stat.h>

int check_is_directory(char *path)
{
    struct stat st;

    if (path && stat(path, &st) == 0 && S_ISDIR(st.st_mode)) {
        write(2, path, my_strlen(path));
        write(2, ": Permission denied.\n", 21);
        return (1);
    }
    return (0);
}

void handle_status(int wait_status, int *status)
{
    if (WIFEXITED(wait_status))
        *status = WEXITSTATUS(wait_status);
    if (WIFSIGNALED(wait_status)) {
        write(2, strsignal(WTERMSIG(wait_status)),
            my_strlen(strsignal(WTERMSIG(wait_status))));
        write(2, "\n", 1);
        *status = 128 + WTERMSIG(wait_status);
    }
}

void launch_process(char *path, char **argv, char **env, int *status)
{
    pid_t pid;
    int wait_status;

    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(1);
    }
    if (pid == 0) {
        execve(path, argv, env);
        perror(argv[0]);
        if (errno == EACCES)
            exit(126);
        else
            exit(1);
    }
    waitpid(pid, &wait_status, 0);
    handle_status(wait_status, status);
}

char *resolve_command_path(char **argv, char **env, int *allocated)
{
    char *path = NULL;

    if (access(argv[0], X_OK) == 0) {
        path = argv[0];
        *allocated = 0;
    } else {
        path = find_command(argv[0], env);
        *allocated = 1;
    }
    if (!path) {
        write(2, argv[0], my_strlen(argv[0]));
        write(2, ": Command not found.\n", 22);
    }
    return path;
}

void execute_command(char **argv, char **env, int *status)
{
    char *path;
    int allocated = 0;

    path = resolve_command_path(argv, env, &allocated);
    if (!path) {
        *status = 127;
        return;
    }
    if (check_is_directory(path)) {
        *status = 126;
        if (allocated)
            free(path);
        return;
    }
    launch_process(path, argv, env, status);
    if (allocated)
        free(path);
}
