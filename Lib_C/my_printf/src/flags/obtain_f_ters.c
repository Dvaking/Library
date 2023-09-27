/*
** EPITECH PROJECT, 2022
** B-CPE-101-BDX-1-1-myprintf-tom.mendy
** File description:
** obtain_f_ters
*/

#include "my.h"

static int put_negatif(char *result, int *negatif_point_addnb, int i)
{
    if (negatif_point_addnb[0] == 1) {
        result[i] = '-';
        return 1;
    }
    return 0;
}

static int put_extra_number(char *result, int *negatif_point_addnb, int i)
{
    if (negatif_point_addnb[2] == 1) {
        result[i] = '1';
        return 1;
    }
    return 0;
}

static int put_point(char *result, int *negatif_point_addnb, int i)
{
    if (negatif_point_addnb[1] == 1) {
        result[i] = '.';
        return 1;
    }
    return 0;
}

void concatenate_result(char *result, char *result_sub,
int *negatif_point_addnb, int count_unit_lenght)
{
    int i = 0;
    int k = 0;
    i += put_negatif(result, negatif_point_addnb, i);
    i += put_extra_number(result, negatif_point_addnb, i);
    while (k < count_unit_lenght) {
        result[i] = result_sub[k];
        i += 1;
        k += 1;
    }
    i += put_point(result, negatif_point_addnb, i);
    while (result_sub[k] != '\0') {
        result[i] = result_sub[k];
        i += 1;
        k += 1;
    }
    result[i] = '\0';
}

int add_space_f(int len, int *bat, char *string)
{
    my_revstr(string);
    for (int i = len; i < bat[3]; i += 1) {
        string[i] = ' ';
    }
    my_revstr(string);
    len = my_strlen(string);
    return len;
}
