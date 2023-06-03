/*
** EPITECH PROJECT, 2023
** B-PSU-200-TLS-2-1-minishell1-leo.maurel
** File description:
** my_strcpy
*/

#include <stdlib.h>

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    if (dest == NULL || src == NULL)
        return (NULL);
    for (; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}

char *my_srtncpy(char *dest, char const *src, int n)
{
    int i = 0;

    if (dest == NULL || src == NULL)
        return (NULL);
    for (; src[i] != '\0' && i < n; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}
