/*
** EPITECH PROJECT, 2023
** B-PSU-200-TLS-2-1-minishell1-leo.maurel
** File description:
** execute_bin
*/

#include "include/mysh.h"

int execute_bin(char **cmd, char *bin)
{
    pid_t pid = fork();

    if (pid == 0) {
        if (execve(bin, cmd, NULL) == -1)
            return (-1);
    } else if (pid > 0) {
        wait(NULL);
    } else {
        my_putstr_error("Error while executing command\n");
        return (-1);
    }
    return (0);
}

int try_execute_bin(char **cmd, char **paths)
{
    char *bin_name = NULL;
    int ret = 0;

    for (int i = 0; paths[i] != NULL; i++) {
        bin_name = my_strdup(paths[i]);
        bin_name = my_strcat(bin_name, "/");
        bin_name = my_strcat(bin_name, cmd[0]);
        if (access(bin_name, F_OK) == 0) {
            break;
        }
    }
    if (bin_name == NULL)
        return (1);
    ret = execute_bin(cmd, bin_name);
    free(bin_name);
    return (ret);
}
