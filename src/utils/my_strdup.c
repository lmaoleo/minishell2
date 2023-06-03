/*
** EPITECH PROJECT, 2023
** B-PSU-200-TLS-2-1-minishell1-leo.maurel
** File description:
** my_strdup
*/

#include <stdlib.h>
#include "mysh.h"

char *my_strdup(char const *src)
{
    int i = 0;
    char *dest = malloc(sizeof(char) * (my_strlen(src) + 1));

    for (; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}

char *my_strndup(char const *src, int n)
{
    int i = 0;
    char *dest = malloc(sizeof(char) * (n + 1));

    for (; src[i] != '\0' && i < n; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}
