/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** minishell.h
*/

#ifndef MYSH_H_
    #define MYSH_H_

    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <string.h>
    #include <signal.h>
    #include <sys/types.h>
    #include <sys/wait.h>

    #include "my_linklist.h"

    struct builtin_s {
        char *name;
        void (*func)(char **, linklist_t *);
    };

    int my_strlen(char const *str);
    int my_putstr(char const *str);
    void my_putstr_error(const char *str);
    int my_putchar(char c);
    int my_putnbr(int nb);
    char *my_strdup(char *src);
    int my_strcmp(char const *s1, char const *s2);
    int my_strncmp(char const *s1, char const *s2, int n);
    char *my_strcat(char *dest, char const *src);
    void *my_realloc(void *ptr, size_t size);
    void *my_memcpy(void *dest, const void *src, size_t n);

    void my_cd(char **cmd, linklist_t *_env);
    void display_pwd(char **_cmd, linklist_t *_env);
    void display_env(char **_cmd, linklist_t *env);
    void set_env(char **cmd, linklist_t *env);
    void unset_env(char **cmd, linklist_t *env);
    int try_execute_bin(char **cmd, char **paths);
    void remove_last_char(char *str);
    int count_char(char *str, char c);
    void display_cmd_response(char *cmd, char *response);
    char ***split_commands(char **cmd);

#endif /* !MYSH_H_ */
