/*
** EPITECH PROJECT, 2023
** B-PSU-200-TLS-2-1-minishell1-leo.maurel
** File description:
** mysh
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>
#include "mysh.h"

static const builtins_t BUILTINS[] = {
    {"cd", &my_cd},
    {"pwd", &my_pwd},
    {"env", &my_env},
    {"setenv", &my_setenv},
    {"unsetenv", &my_unsetenv},
    {"exit", &my_exit},
    {NULL, NULL}
};

static int exec_builtin(char **input, env_t *env)
{
    int status = 0;

    for (int i = 0; BUILTINS[i].name != NULL; i++) {
        if (my_strcmp(input[0], BUILTINS[i].name) == 0) {
            status = BUILTINS[i].func(input, env);
            return (status);
        }
    }
    return (-2);
}

static void input_loop(char **input, env_t *env_cpy,
int *status, int *last_status)
{
    *status = exec_builtin(input, env_cpy);
    if (*status == -2) {
        *status = 0;
        *last_status = exec_bin(input, env_cpy);
    }
}

int main(int ac, char **av, char **env)
{
    (void) ac;
    (void) av;
    char **input = init_input();
    env_t *env_cpy = char_to_env(env);
    int status = 0;
    int last_status = 0;

    while (status == 0) {
        free_input(input);
        input = get_input();
        if (input == NULL)
            break;
        if (input[0][0] == '\0')
            continue;
        input_loop(input, env_cpy, &status, &last_status);
    }
    free_input(input);
    free_env(env_cpy);
    return (last_status);
}
