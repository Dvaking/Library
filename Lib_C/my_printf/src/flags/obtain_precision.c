/*
** EPITECH PROJECT, 2022
** obtain precision
** File description:
** obtain the numbre
*/

#include <stdio.h>
#include "my.h"

int precision(char const *str, int *bat, int i)
{
    while (str[i] >= '0' && str[i] <= '9') {
        bat[2] = (bat[2] * 10) + (str[i] - 48);
        i += 1;
    }
    return i;
}

int *obtain_precision(char const *str, int *bat)
{
    int i = 0;
    while (i < my_strlen(str)) {
        if (str[i] == '#') {
            bat[0] += 1;
            i += 1;
        }
        if (str[i] == '.') {
            bat[1] += 1;
            i += 1;
            i = precision(str, bat, i);
        }
        if (str[i] >= '0' && str[i] <= '9') {
            bat[3] = bat[3] * 10 + (str[i] - 48);
            i += 1;
        }
    }
    return bat;
}
