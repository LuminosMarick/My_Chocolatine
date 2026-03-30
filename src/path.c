/*
** EPITECH PROJECT, 2026
** minishell
** File description:
** Made By Ozy
*/

#include "../include/minishell.h"

char *get_path_env(char **env)
{
    int i = 0;

    while (env[i]) {
        if (my_strncmp(env[i], "PATH=", 5) == 0)
            return env[i] + 5;
        i++;
    }
    return NULL;
}

char *build_path(char *dir, char *cmd)
{
    char *full = malloc(strlen(dir) + strlen(cmd) + 2);

    if (!full)
        return NULL;
    my_strcpy(full, dir);
    my_strcat(full, "/");
    my_strcat(full, cmd);
    return full;
}

char *find_command(char *cmd, char **env)
{
    char *path_env = get_path_env(env);
    char *path;
    char *dir;
    char *full;

    if (!path_env)
        return NULL;
    path = my_strdup(path_env);
    dir = strtok(path, ":");
    while (dir) {
        full = build_path(dir, cmd);
        if (access(full, X_OK) == 0) {
            free(path);
            return full;
        }
        free(full);
        dir = strtok(NULL, ":");
    }
    free(path);
    return NULL;
}
