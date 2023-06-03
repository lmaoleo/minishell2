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

char *init_input(void)
{
    char *input = malloc(sizeof(char) * 1);

    input[0] = '\0';
    return (input);
}

char *get_input(void)
{
    char *input = NULL;
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
    return (input);
}
