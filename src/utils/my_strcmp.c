/*
** EPITECH PROJECT, 2023
** B-PSU-200-TLS-2-1-minishell1-leo.maurel
** File description:
** my_strcmp
*/

int my_strcmp(char *str1, char *str2)
{
    int i = 0;

    for (; str1[i] != '\0' && str2[i] != '\0'; i++) {
        if (str1[i] != str2[i])
            return (1);
    }
    if (str1[i] != str2[i])
        return (1);
    return (0);
}

int my_strncmp(char *str1, char *str2, int n)
{
    int i = 0;

    for (; str1[i] != '\0' && str2[i] != '\0' && i < n; i++) {
        if (str1[i] != str2[i])
            return (1);
    }
    return (0);
}

int my_char_in_str(char *str, char c)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == c)
            return (1);
    return (0);
}
