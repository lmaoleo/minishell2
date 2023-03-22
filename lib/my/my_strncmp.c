/*
** EPITECH PROJECT, 2022
** B-CPE-100-TLS-1-1-cpoolday06-leo.maurel
** File description:
** my_strncmp
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    for (; s1[i] != '\0' && s2[i] != '\0' && i < n; i++) {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
    }
    if (i < n) {
        if (s1[i] == '\0' && s2[i] != '\0')
            return (-s2[i]);
        if (s1[i] != '\0' && s2[i] == '\0')
            return (s1[i]);
    }
    return (0);
}
