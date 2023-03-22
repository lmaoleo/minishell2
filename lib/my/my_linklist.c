/*
** EPITECH PROJECT, 2023
** B-PSU-200-TLS-2-1-minishell1-leo.maurel
** File description:
** my_linklist
*/

#include "../../include/my_linklist.h"

linklist_t *create_linklist(void)
{
    linklist_t *list = malloc(sizeof(linklist_t));

    if (list == NULL)
        return (NULL);
    list->data = NULL;
    list->next = list;
    list->prev = list;
    return (list);
}

linklist_t *append_linklist(linklist_t *node, void *data)
{
    linklist_t *new = malloc(sizeof(linklist_t));

    if (new == NULL)
        return (NULL);
    new->data = data;
    new->next = node->next;
    new->prev = node;
    node->next->prev = new;
    node->next = new;
    return (new);
}

linklist_t *remove_linklist(linklist_t *node)
{
    linklist_t *tmp = node;

    if (node->data == NULL)
        return (NULL);
    node->prev->next = node->next;
    node->next->prev = node->prev;
    node = node->next;
    free(tmp);
    return (node);
}

linklist_t *pop_linklist(linklist_t *node)
{
    linklist_t *poped = node;

    remove_linklist(node);
    return (poped);
}

linklist_t *get_start_linklist(linklist_t *node)
{
    while (node->prev->data != NULL)
        node = node->prev;
    return (node);
}
