/*
** EPITECH PROJECT, 2022
** decimal_to_other_base
** File description:
** function that converts and displays a
** decimal number into a number in a given base
*/

#include <stdlib.h>
#include <stdio.h>

char *my_revstr(char *str);
int print_string(char const * str);

static char *base_digit(int nb_base)
{
    if (nb_base == 2)
        return "01";
    if (nb_base == 8)
        return "01234567";
    if (nb_base == 16)
        return "0123456789ABCDEF";
}

char *decimal_to_other_base(unsigned int nbr, int nb_base)
{
    int count = 0;
    unsigned int save_nbr = nbr;
    char *base = base_digit(nb_base);
    while (nbr != 0) {
        nbr = nbr / nb_base;
        count += 1;
    }
    char *result = malloc(sizeof(char) * count);
    for (int i = 0; i < count; i += 1) {
        result[i] = base[save_nbr % nb_base];
        save_nbr = save_nbr / nb_base;
    }
    result[count] = '\0';
    my_revstr(result);
    return result;
}
