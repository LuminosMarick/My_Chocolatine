/*
** EPITECH PROJECT, 2025
** base_function
** File description:
** Made By Ozy And Oceanne
*/
#include <stdio.h>
#include <unistd.h>
#include "../include/minishell.h"
#include <stdarg.h>
#include <stdint.h>

int my_putchar(char c)
{
    write(1, &c, 1);
    return 1;
}

int my_put_nbr(int nb)
{
    int count = 0;

    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
        count++;
    }
    if (nb >= 10) {
        my_put_nbr(nb / 10);
        count++;
    }
    my_putchar('0' + (nb % 10));
    return count;
}

int my_putstr(char const *str)
{
    int i = 0;
    int count = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
        count++;
    }
    return count;
}

char *my_strstr(char *str, char *to_find)
{
    int i = 0;
    int j;

    if (to_find[0] == '\0')
        return str;
    while (str[i] != '\0') {
        j = 0;
        while (str[i + j] == to_find[j] && to_find[j] != '\0') {
            j++;
        }
        if (to_find[j] == '\0')
            return &str[i];
        i++;
    }
    return 0;
}
