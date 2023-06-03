/*
** EPITECH PROJECT, 2023
** B-PSU-200-TLS-2-1-minishell1-leo.maurel
** File description:
** setenv
*/

#include <stdlib.h>
#include "mysh.h"

int my_setenv(char **input, env_t *env)
{
    if (input[1] == NULL) {
        my_env(input, env);
        return (0);
    }
    char *value = get_env_value(env, input[1]);
    if (value != NULL) {
        if (input[2] != NULL)
            set_env_value(env, input[1], input[2]);
        else
            set_env_value(env, input[1], "");
    } else {
        if (input[2] != NULL)
            add_env_value(env, input[1], input[2]);
        else
            add_env_value(env, input[1], "");
    }
    return (0);
}

int my_unsetenv(char **input, env_t *env)
{
    if (input[1] == NULL) {
        my_putstr("unsetenv: Too few arguments.\n");
        return (0);
    }
    remove_env_value(&env, input[1]);
    return (0);
}
