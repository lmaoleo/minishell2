/*
** EPITECH PROJECT, 2023
** B-PSU-200-TLS-2-1-minishell1-leo.maurel
** File description:
** get_input
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "mysh.h"

char **init_input(void)
{
    char **input = malloc(sizeof(char *) * 2);

    input[0] = malloc(sizeof(char) * 1);
    input[0] = my_strcpy(input[0], "");
    input[1] = NULL;
    return (input);
}

void free_input(char **input)
{
    if (input == NULL)
        return;
    for (int i = 0; input[i] != NULL; i++) {
        free(input[i]);
    }
    free(input);
}

void clear_empty_str(char **input)
{
    for (int i = 1; input[i] != NULL; i++) {
        if (my_strcmp(input[i], "") == 0) {
            input[i] = NULL;
        }
    }
}

char **get_input(void)
{
    char *input = NULL;
    char **splited = NULL;
    size_t len = 0;
    ssize_t read = 0;

    my_putstr("$> ");
    read = getline(&input, &len, stdin);
    if (read == -1) {
        my_exit(NULL, NULL);
        free(input);
        return (NULL);
    }
    my_strclean(input);
    splited = my_str_split_chars(input, " \n\t");
    free(input);
    clear_empty_str(splited);
    return (splited);
}
