/*
** EPITECH PROJECT, 2022
** B-CPE-101-BDX-1-1-myprintf-tom.mendy
** File description:
** obtain_s
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

#include "my.h"

int find_max(int space, int len)
{
    int max = -1;
    if (space > max) {
        max = space;
    }
    if (len > max) {
        max = len;
    }
    return max;
}

int find_len_world(int precision, char *s)
{
    int len = -1;
    if (precision > -1){
        len = precision;
    } else {
        len = my_strlen(s);
    }
    return len;
}

static char *obtain_s_sub(int space, int precision, char *s)
{
    char *str;
    int j = 0;
    int len = find_len_world(precision, s);
    int max = find_max(space, len);
    str = malloc(sizeof(char) * space);
    for (int i = 0; i < max - len; i += 1) {
        str[j] = ' ';
        j += 1;
    }
    for (int i = 0; i < len; i += 1) {
        str[j] = s[i];
        j += 1;
    }
    return str;
}

int obtain_s(char *str, va_list list)
{
    int pres = -1;
    int space = 0;
    if (str[0] != '%'){
        int bat[] = {0, 0, 0, 0};
        obtain_precision(str, bat);
        if (bat[0] > 1 || bat[1] > 1){
            print_char('%');
            int len = print_string(str);
            print_char('f');
            return 2 + len;
        }
        if (bat[1] == 1)
            pres = bat[2];
        if (bat[3] > 0)
            space = bat[3];
    }
    char *rts = obtain_s_sub(space, pres, va_arg(list, char *));
    int len = print_string(rts);
    return len;
}
