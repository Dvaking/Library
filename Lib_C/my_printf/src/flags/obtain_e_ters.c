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

static int put_lettre_expo(char *result, int i)
{
    result[i] = 'e';
    return 1;
}

void concatenate_result_e(char *result, char *result_sub,
    int *negatif_point_addnb, int p)
{
    int i = 0;
    int k = 0;
    i += put_negatif(result, negatif_point_addnb, i);
    if (put_extra_number(result, negatif_point_addnb, i) == 1) {
        i += 1;
        p += 1;
        i += put_point(result, negatif_point_addnb, i);
    } else {
        result[i] = result_sub[k];
        i += 1;
        i += put_point(result, negatif_point_addnb, i);
    }
    k += 1;
    while (result_sub[k] != '\0') {
        result[i] = result_sub[k];
        i += 1;
        k += 1;
    }
    i += put_lettre_expo(result, i);
    i = put_nb_expo(result, p, i);
}
