/*
** EPITECH PROJECT, 2022
** B-CPE-101-BDX-1-1-myprintf-tom.mendy
** File description:
** obtain_e_quad
*/

#include <stdlib.h>
#include "my.h"

static void put_signe_expo(char *result, int *p, int i)
{
    if (*p < 0) {
        *p = -(*p);
        result[i] = '-';
    } else {
        result[i] = '+';
    }
}

static void condition(char *result, int *i, int *p)
{
    if (*p == 0) {
        result[*i] = '0';
        *i += 1;
    }
    if (*p < 10) {
        result[*i] = '0';
        *i += 1;
    }
}

int put_nb_expo(char *result, int p, int i)
{
    put_signe_expo(result, &p, i);
    int save_p = p;
    i += 1;
    condition(result, &i, &p);
    while (p > 0) {
        result[i] = (p % 10) + 48;
        p /= 10;
        i += 1;
    }
    i -= 1;
    if (save_p >= 10) {
        char temp = result[i];
        result[i] = result[i - 1];
        result[i - 1] = temp;
    }
    return i;
}

int add_space_e(int len, int *bat, char *string)
{
    my_revstr(string);
    for (int i = len; i < bat[3]; i += 1) {
        string[i] = ' ';
    }
    my_revstr(string);
    len = my_strlen(string);
    return len;
}

char *case_0(void)
{
    char *str_0 = malloc(sizeof(char) * 13);
    for (int i = 0; i < 13; i += 1) {
        str_0[i] = '0';
    }
    str_0[1] = '.';
    str_0[8] = 'e';
    str_0[9] = '+';
    str_0[12] = '\0';
    return str_0;
}
