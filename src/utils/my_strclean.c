/*
** EPITECH PROJECT, 2023
** B-PSU-200-TLS-2-1-minishell1-leo.maurel
** File description:
** my_steclean
*/

#include <stdlib.h>
#include "mysh.h"

void skip_spaces(char *str, int *i)
{
    for (; str[*i] == ' ' || str[*i] == '\t'; (*i)++);
}

void my_strclean(char *str)
{
    int i = 0;
    int j = 0;

    skip_spaces(str, &i);
    for (; str[i] != '\0'; i++) {
        if (str[i] == ' ' || str[i] == '\t') {
            str[j] = ' ';
            j++;
            skip_spaces(str, &i);
            i--;
        } else {
            str[j] = str[i];
            j++;
        }
    }
    str[j] = '\0';
}
