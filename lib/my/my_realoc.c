/*
** EPITECH PROJECT, 2023
** B-PSU-200-TLS-2-1-minishell1-leo.maurel
** File description:
** my_realoc
*/

#include "../../include/mysh.h"

void *my_memcpy(void *dest, const void *src, size_t n)
{
    char *cdest = (char *)dest;
    const char *csrc = (const char *)src;

    for (size_t i = 0; i < n; i++) {
        cdest[i] = csrc[i];
    }
    return dest;
}

void *my_memdup(const void *src, size_t n)
{
    void *dest = malloc(n);

    if (dest == NULL)
        return (NULL);
    return (my_memcpy(dest, src, n));
}

void *my_realloc(void *ptr, size_t size)
{
    void *new_ptr = NULL;

    if (ptr == NULL)
        return (malloc(size));
    if (size == 0) {
        free(ptr);
        return (NULL);
    }
    new_ptr = my_memdup(ptr, size);
    free(ptr);
    return (new_ptr);
}
