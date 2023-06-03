/*
** EPITECH PROJECT, 2023
** B-PSU-200-TLS-2-1-minishell1-leo.maurel
** File description:
** env_utils
*/

#include <stdlib.h>
#include <stdio.h>
#include "mysh.h"

static int env_len(env_t *env)
{
    int i = 0;

    for (env_t *tmp = env; tmp != NULL; tmp = tmp->next, i++);
    return (i - 1);
}

char **env_to_char(env_t *env)
{
    char **new_env = malloc(sizeof(char *) * (env_len(env) + 1));
    int i = 0;

    for (env_t *tmp = env; tmp->next != NULL;) {
        tmp = tmp->next;
        new_env[i] = my_strdup(tmp->value);
        i++;
    }
    new_env[i] = NULL;
    return (new_env);
}

env_t *char_to_env(char **env)
{
    env_t *new_env = malloc(sizeof(env_t));
    env_t *tmp = new_env;
    int i = 0;

    tmp->value = NULL;
    tmp->next = malloc(sizeof(env_t));
    tmp = tmp->next;
    for (; env[i + 1] != NULL; i++) {
        tmp->value = my_strdup(env[i]);
        tmp->next = malloc(sizeof(env_t));
        tmp = tmp->next;
    }
    tmp->value = my_strdup(env[i]);
    tmp->next = NULL;
    return (new_env);
}

void free_env(env_t *env)
{
    env_t *tmp = env;

    while (tmp->next != NULL) {
        tmp = tmp->next;
        free(tmp->value);
        free(env);
        env = tmp;
    }
    free(env);
}

void free_tab(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++) {
        free(tab[i]);
    }
    free(tab);
}
