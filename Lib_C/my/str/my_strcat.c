/*
** EPITECH PROJECT, 2022
** my_strcat
** File description:
** rajoute le mot de 1 dans 2
*/

#include <unistd.h>
#include <stdlib.h>
#include "proto_lib.h"

char *my_strcat(char *dest, char const *src)
{
    int len_dest = 0;
    int len_src = 0;
    int count = 0;
    if (dest == NULL || src == NULL)
        return NULL;
    if ((len_dest = my_strlen(dest)) == -1 || (len_src = my_strlen(src)) == -1)
        return NULL;
    char *tmp = malloc(sizeof(char) * (len_dest + len_src) + 1);
    for (int i = 0; dest[i] != '\0'; i += 1){
        tmp[count] = dest[i];
        count += 1;
    }
    for (int i = 0; src[i] != '\0'; i += 1){
        tmp[count] = src[i];
        count += 1;
    }
    tmp[count] = '\0';
    return tmp;
}
