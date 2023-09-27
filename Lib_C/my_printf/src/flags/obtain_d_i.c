/*
** EPITECH PROJECT, 2022
** obtain_d_i
** File description:
** pour affichier une valeur decimal
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

static char *print_d_i(int neg, int count, char *str, int save_result)
{
    str = malloc(sizeof(char) * count);
    if (neg == 1) {
        str[count - 1] = '-';
        for (int i = 0; i < count - 1; i = i + 1){
            str[i] = (save_result % 10) + 48;
            save_result = save_result / 10;
        }
    } else {
        for (int i = 0; i < count; i = i + 1){
            str[i] = (save_result % 10) + 48;
            save_result = save_result / 10;
        }
    }
    return (str);
}

static char *obtain_d_i_sub(int p, int nbr)
{
    int count = 0;
    int negativ = 0;
    int result = nbr;
    char *str;
    if (nbr < 0) {
        result = nbr * -1;
        count = count + 1;
        negativ += 1;
    }
    int save_result = result;
    if (result == 0)
        count = count + 1;
    while (result != 0) {
        count = count + 1;
        result = result / 10;
    }
    str = print_d_i(negativ, count, str, save_result);
    my_revstr(str);
    return (str);
}

int obtain_d_i(char *str, va_list list)
{
    char *rts = obtain_d_i_sub(0, va_arg(list, int));
    int pres = 0;
    int with = 0;
    if (str[0] != '%'){
        int bat[] = {0, 0, 0, 0};
        obtain_precision(str, bat);
        if (bat[1] > 1){
            print_char('%');
            int len = print_string(str);
            print_char('d');
            return 2 + len;
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
