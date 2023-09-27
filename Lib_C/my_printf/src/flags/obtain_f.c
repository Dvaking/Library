/*
** EPITECH PROJECT, 2022
** B-CPE-101-BDX-1-1-myprintf-tom.mendy
** File description:
** obtain_f
*/

#include <stdlib.h>
#include <stdarg.h>
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

static void creat_unit(double *save_nb, int count, char *unit)
{
    for (int i = 0; i < count; i += 1) {
        unit[i] = ((int)*save_nb % 10) + 48;
        *save_nb = *save_nb - (int)*save_nb % 10;
        *save_nb = *save_nb / 10;
    }
    unit[count] = '\0';
    my_revstr(unit);
}

static void creat_decimal(double *save_nb, char *decimal, int precision,
    int count)
{
    *save_nb = *save_nb * my_compute_power_rec(10, count);
    for (int i = 0; i < precision; i += 1) {
        *save_nb *= 10;
        decimal[i] = ((int)*save_nb % 10) + 48;
        *save_nb = *save_nb - ((int)*save_nb % 10);
    }
    decimal[precision] = '\0';
}

char *obtain_f_sub(int argument_hatag, int precision, double nb)
{
    int negatif_point_addnb[3] = {0, 0, 0};
    negatif_point_fonction(&nb, precision,
    negatif_point_addnb, argument_hatag);
    double save_nb = nb;
    int count_unit_lenght = find_count_unit_lenght(nb);
    char unit[count_unit_lenght + 1];
    char decimal[precision + 1];
    creat_unit(&save_nb, count_unit_lenght, unit);
    creat_decimal(&save_nb, decimal, precision, count_unit_lenght);
    char *result_sub = malloc(sizeof(char) * (my_strlen(unit) +
    my_strlen(decimal)));
    concatenate(result_sub, unit, decimal);
    negatif_point_addnb[2] = round_nb(save_nb, result_sub);
    char *result = malloc(sizeof(char) * (count_unit_lenght +
    precision + negatif_point_addnb[0] + negatif_point_addnb[1] +
    negatif_point_addnb[2]));
    concatenate_result(result, result_sub, negatif_point_addnb,
    count_unit_lenght);
    free(result_sub);
    return result;
}

int obtain_f(char *str, va_list list)
{
    int pres = 6;
    int argument_hatag = 0;
    int bat[] = {0, 0, 0, 0};
    if (str[0] != '%'){
        obtain_precision(str, bat);
        if (bat[0] > 1 || bat[1] > 1){
            print_char('%');
            int len = print_string(str);
            print_char('f');
            return 2 + len;
        }
        if (bat[1] == 1)
            pres = bat[2];
    }
    char *string = obtain_f_sub(bat[0], pres, va_arg(list, double));
    if (bat[3] > 0 && bat[3] > my_strlen(string)) {
        add_space_f(my_strlen(string), bat, string);
    }
    int len = print_string(string);
    return len;
}
