/*
** EPITECH PROJECT, 2022
** B-CPE-101-BDX-1-1-miniprintf-tom.mendy
** File description:
** my_printf
*/

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "structab.h"

const struct tab OPERATORS_FUNCS[] = {
    {'c', &obtain_c},
    {'s', &obtain_s},
    {'d', &obtain_d_i},
    {'i', &obtain_d_i},
    {'e', &obtain_e},
    {'p', &obtain_p},
    {'E', &obtain_e},
    {'u', &obtain_u},
    {'o', &obtain_o},
    {'f', &obtain_f},
    {'F', &obtain_f},
    {'g', &obtain_g},
    {'b', &obtain_b},
    {'x', &obtain_x},
    {'X', &obtain_x_maj},
    {'%', &obtain_percent},
    {'N', NULL}
};

static char *precision(int i, char const *format)
{
    int count = 0;

    while ((format[i] == '.') || ((format[i] >= '0') && (format[i] <= '9'))
    || (format[i] == '#')) {
        count = count + 1;
        i += 1;
    }
    char *gnirts = malloc(sizeof(char) * count);
    for (int b = 0; b < count; b += 1){
        gnirts[b] = format[i - count + b];
    }
    return (gnirts);
}

static int flag_n(va_list list, int i)
{
    *(va_arg(list, int *)) = i;
    return (2);
}

static int pattern(char const *format, va_list list, int *i)
{
    int j = 0;
    char *rts = "%";

    if ((format[*i] == '.') || ((format[*i] >= '0') && (format[*i] <= '9'))
    || (format[*i] == '#')){
        rts = precision(*i, format);
        *i += my_strlen(rts);
    }
    while (OPERATORS_FUNCS[j].c != 'N') {
        if (format[*i] == OPERATORS_FUNCS[j].c) {
            return OPERATORS_FUNCS[j].flags(rts, list);
        }
        j += 1;
    }
    print_char('%');
    print_char(format[*i]);
    return 1;
}

int my_printf(char const *format, ...)
{
    int i = 0;
    int count = 0;
    va_list list;

    va_start(list, format);
    while (format[i] != '\0') {
        if (format[i] == '%' && format[i + 1] == 'n')
            i += flag_n(list, i);
        if (format[i] == '%') {
            i += 1;
            count += pattern(format, list, &i);
            i += 1;
        } else {
            print_char(format[i]);
            i += 1;
            count += 1;
        }
    }
    va_end(list);
    return count;
}
