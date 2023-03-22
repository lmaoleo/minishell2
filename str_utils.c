/*
** EPITECH PROJECT, 2023
** B-PSU-200-TLS-2-1-minishell1-leo.maurel
** File description:
** str_utils
*/

#include "include/mysh.h"

void remove_last_char(char *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    str[i - 1] = '\0';
}

int count_char(char *str, char c)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == c)
            count++;
    return (count);
}

void display_cmd_response(char *cmd, char *response)
{
    my_putstr(cmd);
    my_putstr(": ");
    my_putstr(response);
    my_putchar('\n');
}
