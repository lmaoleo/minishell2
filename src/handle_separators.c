/*
** EPITECH PROJECT, 2023
** B-PSU-200-TLS-2-1-minishell2-leo.maurel
** File description:
** split_sarators
*/

#include <stdlib.h>
#include <stdio.h>
#include "mysh.h"

static void clear_empty_str(char **str)
{
    for (int i = 1; str[i] != NULL; i++) {
        if (my_strcmp(str[i], "") == 0) {
            str[i] = NULL;
        }
    }
}

void execute_semicolon_split(char *input, env_t *env_cpy,
int *status, int *last_status)
{
    char **semicolon_split = my_str_split_chars(input, ";");
    char **this_input = NULL;

    clear_empty_str(semicolon_split);
    for (int i = 0; semicolon_split[i] != NULL; i++) {
        if (semicolon_split == NULL)
            break;
        if (semicolon_split[0][0] == '\0')
            continue;
        my_strclean(semicolon_split[i]);
        this_input = my_str_split_chars(semicolon_split[i], " \t\n");
        clear_empty_str(this_input);
        input_loop(this_input, env_cpy, status, last_status);
        free_tab(this_input);
    }
    free_tab(semicolon_split);
}
