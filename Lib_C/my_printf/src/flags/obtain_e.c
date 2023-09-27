/*
** EPITECH PROJECT, 2022
** obtain_e
** File description:
** double en affichage scientifique
*/

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "my.h"

static int *negatif_point_fonction(double *nb, int precision,
    int *negatif_point, int argument_hatag)
{
    if (*nb < 0) {
        *nb = -(*nb);
        negatif_point[0] = 1;
    }

    if (precision > 0 || argument_hatag == 1) {
        negatif_point[1] = 1;
    }
    return negatif_point;
}

static void creat_unit(double *save_nb, char *unit)
{
    *unit = ((int)*save_nb % 10) + 48;
    *save_nb = *save_nb - (int)*save_nb % 10;
    *save_nb = *save_nb / 10;
    *save_nb = *save_nb * 10;
}

static void creat_decimal(double *save_nb, char *decimal, int precision)
{
    for (int i = 0; i < precision; i += 1) {
        *save_nb *= 10;
        decimal[i] = ((int)*save_nb % 10) + 48;
        *save_nb = *save_nb - ((int)*save_nb % 10);
    }
    decimal[precision] = '\0';
}

char *obtain_e_sub(int precision, int argument_hatag, double nb)
{
    if (nb == 0) {
        char *str_0 = case_0();
        return str_0;
    }
    int negatif_point_addnb[3] = { 0, 0, 0 };
    negatif_point_fonction(&nb, precision, negatif_point_addnb,
        argument_hatag);
    int p = get_p(&nb);
    char unit;
    char decimal[precision + 1];
    creat_unit(&nb, &unit);
    creat_decimal(&nb, decimal, precision);
    char *result_sub = malloc(sizeof(char) * (1 + my_strlen(decimal)));
    concatenate_e(result_sub, unit, decimal);
    negatif_point_addnb[2] = round_nb(nb, result_sub);
    char *str = malloc(sizeof(char) * (negatif_point_addnb[0] +
        negatif_point_addnb[1] + 1 + precision + 3));
    concatenate_result_e(str, result_sub, negatif_point_addnb, p);
    free(result_sub);
    return str;
}

int obtain_e(char *str, va_list list)
{
    int pres = 6;
    int bat[] = { 0, 0, 0, 0 };
    if (str[0] != '%') {
        obtain_precision(str, bat);
        if (bat[0] > 1 || bat[1] > 1) {
            print_char('%');
            int len = print_string(str);
            print_char('e');
            return 2 + len;
        }
        if (bat[1] == 1)
            pres = bat[2];
    }
    char *string = obtain_e_sub(pres, bat[0], va_arg(list, double));
    if (bat[3] > 0 && bat[3] > my_strlen(string)) {
        add_space_e(my_strlen(string), bat, string);
    }
    int len = print_string(string);
    return len;
}
