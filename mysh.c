/*
** EPITECH PROJECT, 2023
** B-PSU-200-TLS-2-1-minishell1-leo.maurel
** File description:
** mysh
*/

#include "include/mysh.h"

const struct builtin_s builtins[] = {
    {"cd", &my_cd},
    {"pwd", &display_pwd},
    {"env", &display_env},
    {"setenv", &set_env},
    {"unsetenv", &unset_env},
    {NULL, NULL}
};

char **get_path(char **env)
{
    char *path = NULL;
    char *path_tok = NULL;
    char **path_tab = NULL;

    for (int i = 0; env[i] != NULL; i++) {
        if (my_strncmp(env[i], "PATH=", 5) == 0) {
            path = my_strdup(env[i]);
            break;
        }
    }
    path_tok = strtok(&path[5], ":");
    for (int i = 0; path_tok != NULL; i++) {
        path_tab = my_realloc(path_tab, sizeof(char *) * (i + 2));
        path_tab[i] = my_strdup(path_tok);
        path_tab[i + 1] = NULL;
        path_tok = strtok(NULL, ":");
    }
    return (path_tab);
}

int check_command(char **cmd, char **paths, linklist_t *env)
{
    for (int i = 0; builtins[i].name != NULL; i++) {
        if (my_strcmp(cmd[0], builtins[i].name) == 0) {
            builtins[i].func(cmd, env);
            return (0);
        }
    }
    if (my_strcmp(cmd[0], "exit") == 0)
        return (1);
    switch (try_execute_bin(cmd, paths)) {
        case 0:
            return (0);
        case -1:
            display_cmd_response(cmd[0], "Command not found");
            return (1);
        default:
            break;
    }
    display_cmd_response(cmd[0], "Permission denied");
    return (0);
}

char **get_input(void)
{
    char *input = NULL;
    char **input_tok = NULL;
    int argc = 0;
    size_t size = 0;

    if (getline(&input, &size, stdin) == -1)
        return (NULL);
    if (input[0] == '\n')
        return (NULL);
    remove_last_char(input);
    argc = count_char(input, ' ') + 1;
    input_tok = malloc(sizeof(char *) * (argc + 1));
    input_tok[argc] = NULL;
    input_tok[0] = strtok(input, " ");
    for (int i = 1; i < argc; i++)
        input_tok[i] = strtok(NULL, " ");
    return (input_tok);
}

int main_loop(char ***cmd_list, char **paths, linklist_t *myenv)
{
    my_putstr("*~ ");
    char **input = get_input();
    if (input == NULL)
        return (-1);
    cmd_list = split_commands(input);
    for (int i = 0; cmd_list[i] != NULL; i++) {
        if (check_command(cmd_list[i], paths, myenv) == 1)
            return (0);
    }
    free(input);
    return (-1);
}

int main(int argc, char **argv, char **env)
{
    char **paths = get_path(env);
    char ***cmd_list = NULL;
    linklist_t *myenv = create_linklist();
    int return_value = 0;

    for (int i = 0; env[i] != NULL; i++)
        append_linklist(myenv, my_strdup(env[i]));
    myenv = get_start_linklist(myenv);
    while (1) {
        return_value = main_loop(cmd_list, paths, myenv);
        if (return_value != -1)
            return (return_value);
    }
    return (0);
}
