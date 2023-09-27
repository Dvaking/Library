/*
** EPITECH PROJECT, 2022
** obtain_p
** File description:
** reccupère la valeur hexa en affichage 0x...
*/

#include <stdlib.h>
#include <stdarg.h>
#include "structab.h"
#include "my.h"

char *my_revstr(char *str);

static char *final_string_sub(char *string, char *rts, int i)
{
    for (int j = 0; rts[j] != '\0'; j += 1) {
        string[i] = rts[j];
        i += 1;
    }
    return (string);
}

static char *final_string(char *string, char *rts, int w)
{
    int count = my_strlen(rts);
    int i = 0;
    string = malloc(sizeof(char) * (count + w));
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

int lenght_pointeur(int count, long int tab)
{
    while (tab != 0) {
        count = count + 1;
        tab = tab / 10;
    }
    return (count);
}

char *obtain_p_sub(int precision, long int nbr)
{
    long int tab = nbr;
    int count = 0;
    int i = 0;
    char *base = "0123456789abcdef";
    char *result;
    if (tab < 0) {
        tab = tab * 1;
        count = count + 1;
    }
    count = lenght_pointeur(count, tab);
    result = malloc(sizeof(int) * count);
    while (tab != 0){
        result[i] = base[tab % 16];
        tab = tab / 16;
        i += 1;
    }
    result[i + 1] = '0';
    result[i] = 'x';
    my_revstr(result);
    return (result);
}

int obtain_p(char *str, va_list list)
{
    char *rts = obtain_p_sub(0, va_arg(list, long int));
    int with = 0;
    if (str[0] != '%'){
        int bat[] = {0, 0, 0, 0};
        obtain_precision(str, bat);
        if (bat[1] > 1){
            print_char('%');
            int len = print_string(str);
            print_char('p');
            return 2 + len;
        }
        if (bat[3] > 0)
            with = bat[3];
    }
    char *srt = final_string(srt, rts, with);
    int len = print_string(srt);
    return len;
}
