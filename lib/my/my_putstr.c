/*
** EPITECH PROJECT, 2022
** B-CPE-100-TLS-1-1-cpoolday04-leo.maurel
** File description:
** my_putstr
*/

#include "../../include/mysh.h"

int my_putstr(const char *str)
{
    int len = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        len += my_putchar(str[i]);
    }
    return len;
}

void my_putstr_error(const char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        write(2, &str[i], 1);
    }
}
