/*
** EPITECH PROJECT, 2023
** B-PSU-200-TLS-2-1-minishell1-leo.maurel
** File description:
** builtins
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include "mysh.h"

static int cd_checks(char **input, char *home, char *old_pwd)
{
    if (home == NULL)
        home = "/home";
    if (input[1] == NULL) {
        chdir(home);
        return (0);
    }
    if (my_strcmp(input[1], "-") == 0) {
        chdir(old_pwd);
        return (0);
    }
    if (access(input[1], F_OK) == -1) {
        print_error(input[1], "No such file or directory.");
        return (1);
    }
    if (opendir(input[1]) == NULL) {
        print_error(input[1], "Not a directory.");
        return (1);
    }
    chdir(input[1]);
    return (0);
}

int my_cd(char **input, env_t *env)
{
    char *home = get_env_value(env, "HOME");
    char *old_pwd = get_env_value(env, "OLDPWD");
    int status = 0;

    set_env_value(env, "OLDPWD", getcwd(NULL, 0));
    status = cd_checks(input, home, old_pwd);
    if (status != 1) {
        set_env_value(env, "PWD", getcwd(NULL, 0));
    }
    if (home != NULL)
        free(home);
    free(old_pwd);
    return (0);
}

int my_pwd(char **input, env_t *env)
{
    (void) input;
    (void) env;
    char *pwd = getcwd(NULL, 0);

    my_putstr(pwd);
    my_putchar('\n');
    free(pwd);
    return (0);
}

int my_env(char **input, env_t *env)
{
    (void) input;
    env_t *tmp = env;
    for (; tmp->next != NULL;) {
        tmp = tmp->next;
        my_putstr(tmp->value);
        my_putchar('\n');
    }
    return (0);
}

int my_exit(char **input, env_t *env)
{
    (void) input;
    (void) env;
    my_putstr("exit\n");
    return (1);
}
