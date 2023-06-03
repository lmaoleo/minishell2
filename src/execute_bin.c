/*
** EPITECH PROJECT, 2023
** B-PSU-200-TLS-2-1-minishell1-leo.maurel
** File description:
** execute_bin
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h>
#include "mysh.h"

static void display_signal(int status)
{
    int termsig = 0;

    if (WIFSIGNALED(status) != 0) {
        termsig = WTERMSIG(status);

        if (termsig != 0 && termsig != SIGFPE) {
            my_putstr(strsignal(termsig));
        }
        if (termsig == SIGFPE) {
            my_putstr("Floating exception");
        }
        if (WCOREDUMP(status) != 0)
            my_putstr(" (core dumped)");
        my_putstr("\n");
    }
}

static char *get_path(char *bin, env_t *env)
{
    char *path = get_env_value(env, "PATH");
    char **paths = NULL;
    char *tmp = NULL;

    if (access(bin, F_OK) == 0 && my_char_in_str(bin, '/') == 1)
        return (bin);
    if (path == NULL)
        return (NULL);
    paths = my_str_split_chars(path, ":");
    for (int i = 0; paths[i] != NULL; i++) {
        tmp = my_strcat(paths[i], "/");
        tmp = my_strcat(tmp, bin);
        if (access(tmp, F_OK) == 0) {
            free_tab(paths);
            return (tmp);
        }
        free(tmp);
    }
    free_tab(paths);
    return (NULL);
}

void print_error(char *bin, char *error)
{
    my_putstr(bin);
    my_putstr(": ");
    my_putstr(error);
    my_putstr("\n");
}

int exec_bin(char **input, env_t *env)
{
    char *path = get_path(input[0], env);
    char **char_env = env_to_char(env);
    int status = 0; int perm = 0;

    if (path == NULL) {
        print_error(input[0], "Command not found.");
        return (1);
    }
    if (fork() == 0) {
        perm = execve(path, input, char_env);
        if (perm == -1)
            print_error(input[0], "Permission denied.");
        exit(0);
    } else
        wait(&status);
    display_signal(status);
    free_tab(char_env);
    return (status);
}
