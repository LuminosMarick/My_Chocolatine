/*
** EPITECH PROJECT, 2026
** minishell
** File description:
** Made By Ozy
*/

#include "../include/minishell.h"

int builtin_cd(char **argv)
{
    if (!argv[1])
        return 0;
    if (chdir(argv[1]) == -1) {
        perror("cd");
        return 1;
    }



    return 0;
}
