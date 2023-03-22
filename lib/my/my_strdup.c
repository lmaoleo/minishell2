/*
** EPITECH PROJECT, 2022
** my_strdup
** File description:
** my_strdup
*/

#include "../../include/mysh.h"

char *my_strdup(char *src)
{
    int i = 0;
    int src_len = my_strlen(src);
    char *dest = malloc(sizeof(char) * (src_len * src_len));

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
