/*
** EPITECH PROJECT, 2023
** B-PSU-200-TLS-2-1-minishell2-leo.maurel
** File description:
** semicolon_handle
*/

#include "include/mysh.h"

int count_commands(char **cmd)
{
    int i = 0;
    int count = 0;

    for (; cmd[i] != NULL; i++) {
        if (my_strcmp(cmd[i], ";") == 0)
            count++;
    }
    return (count);
}

int count_args(char **cmd, int i)
{
    int count = 0;

    for (; cmd[i] != NULL && my_strcmp(cmd[i], ";") != 0; i++)
        count++;
    return (count);
}

char ***split_commands(char **cmd)
{
    int i = 0;
    int j = 0;
    int k = 0;
    char ***commands = malloc(sizeof(char **) * (count_commands(cmd) + 1));

    if (commands == NULL)
        return (NULL);
    for (; cmd[i] != NULL; i++) {
        commands[j] = malloc(sizeof(char *) * (count_args(cmd, i) + 1));
        if (commands[j] == NULL)
            return (NULL);
        for (k = 0; cmd[i] != NULL && my_strcmp(cmd[i], ";") != 0; k++, i++)
            commands[j][k] = cmd[i];
        commands[j][k] = NULL;
        j++;
    }
    commands[j] = NULL;
    return (commands);
}
