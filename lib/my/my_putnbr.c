/*
** EPITECH PROJECT, 2023
** B-PSU-100-TLS-1-1-navy-louis.roques
** File description:
** my_putnbr
*/

#include "../../include/mysh.h"

int my_putnbr(int nb)
{
    int len = 0;

    if (nb == -2147483648) {
        my_putchar('-');
        my_putchar('2');
        nb = 147483648;
        len += 2;
    }
    if (nb < 0) {
        len += my_putchar('-');
        nb = nb * -1;
    }
    if (nb >= 10) {
        len += my_putnbr(nb / 10);
        len += my_putnbr(nb % 10);
    } else {
        char a = nb + '0';
        len += my_putchar(a);
    }
    return len;
}
