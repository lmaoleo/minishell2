/*
** EPITECH PROJECT, 2022
** B-CPE-100-TLS-1-1-cpoolday06-leo.maurel
** File description:
** my_strlen
*/

int my_strlen(const char *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    return (i);
}
