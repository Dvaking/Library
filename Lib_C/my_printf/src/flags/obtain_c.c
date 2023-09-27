/*
** EPITECH PROJECT, 2022
** B-CPE-101-BDX-1-1-myprintf-tom.mendy
** File description:
** obtain_c
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include "my.h"

static char *obtain_c_sub(int space, char c)
{
    char *str;
    str = malloc(sizeof(char) * (space + 1));
    str[0] = c;
    for (int i = 1; i < space; i += 1){
        str[i] = ' ';
    }
    my_revstr(str);
    return str;
}

int obtain_c(char *str, va_list list)
{
    int space = 0;
    int len = 0;
    if (str[0] != '%'){
        int bat[] = {0, 0, 0, 0};
        obtain_precision(str, bat);
        if (bat[0] > 1 || bat[1] > 1){
            print_char('%');
            len = print_string(str);
            print_char('c');
            return 2 + len;
        }
        if (bat[3] > 0)
            space = bat[3];
    }
    char *rts = obtain_c_sub(space, va_arg(list, int));
    len = print_string(rts);
    return len;
}
