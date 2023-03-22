/*
** EPITECH PROJECT, 2022
** B-CPE-100-TLS-1-1-cpoolday06-leo.maurel
** File description:
** my_strcmp
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    for (; s1[i] != '\0' && s2[i] != '\0'; i++) {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
    }
    if (s1[i] == '\0' && s2[i] != '\0')
        return (-s2[i]);
    if (s1[i] != '\0' && s2[i] == '\0')
        return (s1[i]);
    return (0);
}
