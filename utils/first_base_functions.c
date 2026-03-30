/*
** EPITECH PROJECT, 2025
** stting_up
** File description:
** Made By Ozy
*/
#include <stdio.h>
#include <stdlib.h>
#include "../include/minishell.h"
#include <stdarg.h>
#include <stdint.h>

char *my_strcpy(char *dest, char const *src)
{
    char *temp = dest;

    *dest = *src;
    while (*src != '\0') {
        dest++;
        src++;
        *dest = *src;
    }
    return temp;
}

void check(char arg, va_list string)
{
    if (arg == '%')
        my_putchar('%');
    if (arg == 'd' || arg == 'i')
        my_put_nbr(va_arg(string, int));
    if (arg == 'c')
        my_putchar(va_arg(string, int));
    if (arg == 's')
        my_putstr(va_arg(string, char *));
}

int my_printf(const char *format, ...)
{
    va_list string;
    int t;

    va_start(string, format);
    for (t = 0; format[t] != '\0'; t++) {
        if (format[t] == '%' && format[t + 1] != '\0') {
            check(format[t + 1], string);
            t++;
            continue;
        }
        my_putchar(format[t]);
    }
    va_end(string);
    return 0;
}

char *my_strchr(char *str, char c)
{
    int i = 0;

    if (!str)
        return NULL;
    while (str[i]) {
        if (str[i] == c)
            return &str[i];
        i++;
    }
    return NULL;
}
