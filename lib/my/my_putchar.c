/*
** EPITECH PROJECT, 2022
** B-CPE-101-TLS-1-1-myprintf-theo.bary
** File description:
** my_putchar
*/

#include <unistd.h>

int my_putchar(char c)
{
    write(1, &c, 1);
    return 1;
}
