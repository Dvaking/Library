/*
** EPITECH PROJECT, 2023
** Minishell2
** File description:
** my_tabcpy
*/

#include <unistd.h>
#include <stdlib.h>

#include "proto_lib.h"

int my_tabcpy(char **src, char ***dest)
{
    int len_tab = 0;
    if (src == NULL)
        return -1;
    if ((len_tab = my_tablen(src)) == -1)
        return -1;
    if (((*dest) = malloc(sizeof(char *)* (len_tab + 1))) == NULL)
        return -1;
    (*dest)[len_tab] = NULL;
    for (int y = 0; src[y] != NULL; y += 1){
        if (my_strcpy(src[y], &(*dest)[y]) == -1)
            return -1;
    }
    return 0;
}
