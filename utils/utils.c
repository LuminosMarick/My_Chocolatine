/*
** EPITECH PROJECT, 2026
** secured
** File description:
** Made with Onias
*/

#include <stdlib.h>
#include "../include/minishell.h"

char *my_strcat(char *dest, char const *str)
{
    int i = 0;
    int j = 0;

    while (dest[i] != '\0') {
        i++;
    }
    while (str[j] != '\0') {
        dest[i + j] = str[j];
        j++;
    }
    dest[i + j] = '\0';
    return dest;
}

int my_strlen(const char *s)
{
    int i = 0;

    while (s && s[i])
        i++;
    return i;
}

char *my_strdup(char *s)
{
    int i = 0;
    int len = my_strlen(s);
    char *dup = malloc(len + 1);

    if (!dup)
        return NULL;
    for (i = 0; i < len; i++)
        dup[i] = s[i];
    dup[len] = '\0';
    return dup;
}

int my_strcmp(char *a, char *b)
{
    int i = 0;

    if (!a || !b)
        return 1;
    while (a[i] && b[i]) {
        if (a[i] != b[i])
            return a[i] - b[i];
        i++;
    }
    return a[i] - b[i];
}

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    while (i < n && s1[i] != '\0' && s1[i] == s2[i]) {
        i++;
    }
    if (i == n) {
        return 0;
    }
    return (unsigned char)s1[i] - (unsigned char)s2[i];
}
