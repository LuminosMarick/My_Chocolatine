/*
** EPITECH PROJECT, 2026
** minishell
** File description:
** Made By Ozy
*/

#include "../include/minishell.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(minishell, find_command_not_found)
{
    char *env[] = {
        "PATH=/bin",
        NULL
    };

    cr_assert_null(find_command("command_that_does_not_exist", env));
}

Test(minishell, cd_absolute_path)
{
    char *env[] = { "HOME=/", NULL };
    char *argv[] = { "cd", "/", NULL };
    char cwd[1024];

    cr_assert_eq(builtin_cd(argv), 0);
    getcwd(cwd, sizeof(cwd));
    cr_assert_str_eq(cwd, "/");
}

Test(minishell, cd_invalid_path)
{
    char *env[] = { NULL };
    char *argv[] = { "cd", "/path/does/not/exist", NULL };

    cr_assert_eq(builtin_cd(argv), 1);
}

Test(minishell, my_strlen)
{
    cr_assert_eq(my_strlen("HELLO"), 5);
    cr_assert_eq(my_strlen(""), 0);
    cr_assert_eq(my_strlen(NULL), 0);
}

Test(minishell, my_strcmp)
{
    cr_assert_eq(my_strcmp("abc", "abc"), 0);
    cr_assert_lt(my_strcmp("abc", "abd"), 0);
    cr_assert_gt(my_strcmp("abd", "abc"), 0);
}

Test(minishell, find_command_null)
{
    char *env[] = { NULL };

    cr_assert_null(find_command(NULL, env));
}