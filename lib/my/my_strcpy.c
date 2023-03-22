/*
** EPITECH PROJECT, 2022
** B-CPE-100-TLS-1-1-cpoolday06-leo.maurel
** File description:
** my_strcpy
*/

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    for (; src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return (dest);
}
