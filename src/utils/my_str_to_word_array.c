/*
** EPITECH PROJECT, 2023
** B-PSU-200-TLS-2-1-minishell1-leo.maurel
** File description:
** my_str_to_word_array
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "mysh.h"

int check_chars(char c, char *chars)
{
    for (int i = 0; chars[i] != '\0'; i++) {
        if (c == chars[i])
            return (1);
    }
    return (0);
}

int split_len(char *str, char *sep)
{
    int i = 0;
    int j = 0;
    int sep_len = my_strlen(sep);

    for (; str[i] != '\0'; i++) {
        if (my_strncmp(&str[i], sep, sep_len) == 0) {
            j++;
            i += sep_len - 1;
        }
    }
    return (j);
}

int split_chars_len(char *str, char *char_seps)
{
    int i = 0;
    int j = 0;

    for (; str[i] != '\0'; i++) {
        if (check_chars(str[i], char_seps) == 1) {
            j++;
        }
    }
    return (j);
}

char **my_str_split(char *str, char *sep)
{
    char **array = malloc(sizeof(char *) * (split_len(str, sep) + 2));
    int j = 0;
    int k = 0;

    array[j] = malloc(sizeof(char) * (my_strlen(str) + 1));
    for (int i = 0; str[i] != '\0'; i++) {
        if (my_strncmp(&str[i], sep, my_strlen(sep)) == 0) {
            array[j][k] = '\0';
            j++;
            array[j] = malloc(sizeof(char) * (my_strlen(str) + 1));
            k = 0;
            i += my_strlen(sep) - 1;
        } else {
            array[j][k] = str[i];
            k++;
        }
    }
    array[j][k] = '\0';
    array[j + 1] = NULL;
    return (array);
}

char **my_str_split_chars(char *str, char *char_seps)
{
    char **array = malloc(sizeof(char *) *
    (split_chars_len(str, char_seps) + 2));
    int j = 0;
    int k = 0;

    array[j] = malloc(sizeof(char) * (my_strlen(str) + 1));
    for (int i = 0; str[i] != '\0'; i++) {
        if (check_chars(str[i], char_seps) == 1) {
            array[j][k] = '\0';
            j++;
            array[j] = malloc(sizeof(char) * (my_strlen(str) + 1));
            k = 0;
        } else {
            array[j][k] = str[i];
            k++;
        }
    }
    array[j][k] = '\0';
    array[j + 1] = NULL;
    return (array);
}
