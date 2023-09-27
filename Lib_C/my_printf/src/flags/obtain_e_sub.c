/*
** EPITECH PROJECT, 2022
** B-CPE-101-BDX-1-1-myprintf-tom.mendy
** File description:
** obtain_e_sub
*/

#include "my.h"

int get_p(double *nb)
{
    int p = 0;
    while (*nb >= 10) {
        *nb /= 10;
        p += 1;
    }
    while (*nb < 1) {
        *nb *= 10;
        p -= 1;
    }
    return p;
}

static void round_nb_sub(double save_nb, char *string_nb, int i)
{
    while (i >= 0) {
        string_nb[i] += 1;
        if ((string_nb[i] - 48) == 10) {
            string_nb[i] = '0';
            i -= 1;
        } else {
            i = -84;
        }
    }
}

int round_nb_e(double save_nb, char *string_nb)
{
    save_nb *= 10;
    char save_first_nb = string_nb[0];
    int i = my_strlen(string_nb) - 1;
    if (((int)save_nb % 10) > 5) {
        round_nb_sub(save_nb, string_nb, i);
    }
    if ((save_first_nb != string_nb[0]) && (string_nb[0] == '0')){
        return 1;
    } else {
        return 0;
    }
}

void concatenate_e(char *result, char unit, char *decimal)
{
    int i = 1;
    result[0] = unit;
    for (int j = 0; decimal[j] != '\0'; j += 1) {
        result[i] = decimal[j];
        i += 1;
    }
}
