/*
** EPITECH PROJECT, 2022
** obtain_g
** File description:
** prend e ou f
*/

#include <stdlib.h>
#include <stdarg.h>
#include "structab.h"
#include "my.h"

static char *correction_value(char *string, int count)
{
    for (int i = count; i != 0; i -= 1) {
        if (string[i] > '0') {
            string[i + 1] = '\0';
            return (string);
        }
    }
}

static char *condition(char *string, char *str, int pres, va_list list)
{
    double machin = va_arg(list, double);
    int count = 0;
    int f = 42;
    if (machin > 1000000.00) {
        string = obtain_e_sub(5, 0, machin);
    } else {
        string = obtain_f_sub(0, 6, machin);
        count = my_strlen(string);
        string = correction_value(string, count);
    }
    return (string);
}

int obtain_g(char *str, va_list list)
{
    char *string;
    string = condition(string, str, 6, list);
    int len = print_string(string);
    return len;
}
