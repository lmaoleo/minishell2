/*
** EPITECH PROJECT, 2023
** B-PSU-200-TLS-2-1-minishell1-leo.maurel
** File description:
** my_strcat
*/

#include <stdlib.h>
#include "mysh.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int j = 0;
    char *new_str = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) +
    1));

    for (; dest[i] != '\0'; i++)
        new_str[i] = dest[i];
    for (; src[j] != '\0'; j++)
        new_str[i + j] = src[j];
    new_str[i + j] = '\0';
    return (new_str);
}
