/*
** EPITECH PROJECT, 2022
** obtain_b
** File description:
** transforme la valluer en bin
*/

#include <stdlib.h>
#include <stdarg.h>
#include "structab.h"
#include "my.h"

static char *final_string_sub(char *string, char *rts, int i)
{
    for (int j = 0; rts[j] != '\0'; j += 1) {
        string[i] = rts[j];
        i += 1;
    }
    return (string);
}

static char *final_string(char *string, char *rts, int p, int w)
{
    int count = my_strlen(rts);
    int i = 0;
    string = malloc(sizeof(char) * (count + p + w));
    if (p > count) {
        while (p > count){
            string[i] = '0';
            i += 1;
            count += 1;
        }
    }
    if (w > count) {
        while (w > count) {
            string[i] = ' ';
            i += 1;
            count += 1;
        }
    }
    my_revstr(string);
    string = final_string_sub(string, rts, i);
    return (string);
}

int obtain_b(char *str, va_list list)
{
    char *rts = decimal_to_other_base(va_arg(list, int), 2);
    int pres = 0;
    int with = 0;
    if (str[0] != '%'){
        int bat[] = {0, 0, 0, 0};
        obtain_precision(str, bat);
        if (bat[1] > 1){
            print_char('%');
            int len = print_string(str);
            print_char('b');
            return len;
        }
        if (bat[1] == 1)
            pres = bat[2];
        if (bat[3] > 0)
            with = bat[3];
    }
    char *srt = final_string(srt, rts, pres, with);
    int len = print_string(srt);
    return len;
}
