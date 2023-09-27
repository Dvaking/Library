/*
** EPITECH PROJECT, 2022
** my_strcpy
** File description:
** sauvegarder un mot dans une autre variable
*/

#include <unistd.h>
#include <stdlib.h>

#include "proto_lib.h"

int my_strcpy(char const *src, char **dest)
{
    int count = 0;
    if (src == NULL)
        return -1;
    if ((count = my_strlen(src)) == -1)
        return -1;
    (*dest) = malloc(sizeof(char) * (count + 1));
    if ((*dest) == NULL)
        return -1;
    for (int i = 0; src[i] != '\0'; i += 1 )
        (*dest)[i] = src[i];
    (*dest)[count] = '\0';
    return 0;
}
