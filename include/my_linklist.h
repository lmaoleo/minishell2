/*
** EPITECH PROJECT, 2023
** B-PSU-200-TLS-2-1-minishell1-leo.maurel
** File description:
** my_linklist
*/

#ifndef MY_LINKLIST_H_
    #define MY_LINKLIST_H_

    #include <stdlib.h>

    typedef struct linklist_s {
        void *data;
        struct linklist_s *next;
        struct linklist_s *prev;
    } linklist_t;

    linklist_t *create_linklist(void);
    linklist_t *append_linklist(linklist_t *node, void *data);
    linklist_t *remove_linklist(linklist_t *node);
    linklist_t *get_start_linklist(linklist_t *node);

#endif /* !MY_LINKLIST_H_ */
