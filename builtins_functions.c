/*
** EPITECH PROJECT, 2023
** B-PSU-200-TLS-2-1-minishell1-leo.maurel
** File description:
** builtins_functions
*/

#include "include/mysh.h"

void my_cd(char **cmd, linklist_t *_env)
{
    if (chdir(cmd[1]) == -1)
        my_putstr("No such file or directory\n");
}

void display_pwd(char **_cmd, linklist_t *_env)
{
    char pwd[1024];

    getcwd(pwd, sizeof(pwd));
    my_putstr(pwd);
    my_putstr("\n");
}

void display_env(char **_cmd, linklist_t *env)
{
    while (env->data != NULL) {
        my_putstr(env->data);
        my_putstr("\n");
        env = env->next;
    }
}

void set_env(char **cmd, linklist_t *env)
{
    char *new_env = cmd[1];
    char *env_tok = strtok(my_strdup(new_env), "=");
    char *realenv_tok = NULL;
    linklist_t *new_node = NULL;

    env = get_start_linklist(env);
    while (env->data != NULL) {
        realenv_tok = my_strdup(env->data);
        realenv_tok = strtok(realenv_tok, "=");
        if (my_strcmp(env_tok, realenv_tok) == 0) {
            free(env->data);
            env->data = my_strdup(new_env);
            return;
        }
        free(realenv_tok);
        env = env->next;
    }
    env = get_start_linklist(env)->prev->prev;
    new_node = append_linklist(env, new_env);
}

void unset_env(char **cmd, linklist_t *env)
{
    char *env_tok = strtok(my_strdup(cmd[1]), "=");
    char *realenv_tok = NULL;

    env = get_start_linklist(env);
    while (env->data != NULL) {
        realenv_tok = my_strdup(env->data);
        realenv_tok = strtok(realenv_tok, "=");
        if (my_strcmp(env_tok, realenv_tok) == 0) {
            remove_linklist(env);
            return;
        }
        free(realenv_tok);
        env = env->next;
    }
}
