/*
** EPITECH PROJECT, 2023
** B-PSU-200-TLS-2-1-minishell1-leo.maurel
** File description:
** mysh
*/

#ifndef MYSH_H_
    #define MYSH_H_

typedef struct env_s {
    char *value;
    struct env_s *next;
} env_t;

typedef struct builtins_s {
    char *name;
    int (*func)(char **, env_t *);
} builtins_t;

char **init_input(void);
void free_input(char **input);
char **get_input(void);
char **env_to_char(env_t *env);
int my_cd(char **input, env_t *env);
int my_pwd(char **input, env_t *env);
int my_env(char **input, env_t *env);
int my_exit(char **input, env_t *env);
int my_setenv(char **input, env_t *env);
int my_unsetenv(char **input, env_t *env);
char **env_to_char(env_t *env);
env_t *char_to_env(char **env);
void free_tab(char **tab);
void free_env(env_t *env);
char *get_env_value(env_t *env, char *name);
void set_env_value(env_t *env, char *name, char *value);
void add_env_value(env_t *env, char *name, char *value);
void remove_env_value(env_t **env, char *name);
int exec_bin(char **input, env_t *env);
void print_error(char *bin, char *error);

int my_putchar(char c);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_strcmp(char *str1, char *str2);
int my_strncmp(char *str1, char *str2, int n);
int my_char_in_str(char *str, char c);
char *my_strcpy(char *dest, char const *src);
char *my_strdup(char const *src);
char *my_strndup(char const *src, int n);
char *my_strcat(char *dest, char const *src);
char **my_str_split(char *str, char *sep);
char **my_str_split_chars(char *str, char *char_seps);
void my_strclean(char *str);

#endif /* !MYSH_H_ */
