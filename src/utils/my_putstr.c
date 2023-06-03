/*
** EPITECH PROJECT, 2023
** B-PSU-200-TLS-2-1-minishell1-leo.maurel
** File description:
** my_putstr
*/

#include <unistd.h>

void my_putstr(char *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    write(1, str, i);
}
