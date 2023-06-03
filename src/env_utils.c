/*
** EPITECH PROJECT, 2023
** B-PSU-200-TLS-2-1-minishell1-leo.maurel
** File description:
** env_utils
*/

#include <stdlib.h>
#include <stdio.h>
#include "mysh.h"

char *get_env_value(env_t *env, char *name)
{
    char **splited_value = NULL;
    char *result = NULL;

    for (env_t *tmp = env; tmp->next != NULL;) {
        tmp = tmp->next;
        splited_value = my_str_split_chars(tmp->value, "=");
        if (my_strcmp(splited_value[0], name) == 0) {
            result = my_strdup(splited_value[1]);
            free(splited_value);
            return (result);
        }
    }
    return (NULL);
}

void set_env_value(env_t *env, char *name, char *value)
{
    char **splited_value = NULL;

    for (env_t *tmp = env; tmp->next != NULL;) {
        tmp = tmp->next;
        splited_value = my_str_split_chars(tmp->value, "=");
        if (my_strcmp(splited_value[0], name) == 0) {
            free(tmp->value);
            tmp->value = my_strcat(name, "=");
            tmp->value = my_strcat(tmp->value, value);
            free(splited_value);
            return;
        }
    }
}

void add_env_value(env_t *env, char *name, char *value)
{
    env_t *tmp = env;
    env_t *new_env = malloc(sizeof(env_t));

    new_env->value = my_strcat(name, "=");
    new_env->value = my_strcat(new_env->value, value);
    new_env->next = NULL;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = new_env;
}

static void remove_env_value_by_pos(env_t **env, env_t *tmp, env_t *prev)
{
    if (prev == NULL) {
        *env = tmp->next;
    } else {
        prev->next = tmp->next;
    }
    free(tmp->value);
    free(tmp);
}

void remove_env_value(env_t **env, char *name)
{
    env_t *tmp = *env;
    env_t *prev = NULL;
    char *splited_value = NULL;

    while (tmp->next != NULL) {
        prev = tmp;
        tmp = tmp->next;
        splited_value = my_str_split_chars(tmp->value, "=")[0];
        if (my_strcmp(splited_value, name) == 0) {
            break;
        }
    }
    if (tmp->next == NULL) {
        return;
    }
    remove_env_value_by_pos(env, tmp, prev);
}
