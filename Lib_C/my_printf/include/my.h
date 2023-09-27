/*
** EPITECH PROJECT, 2022
** B-CPE-101-BDX-1-1-myprintf-tom.mendy
** File description:
** my
*/

#include <stdarg.h>

#ifndef MY_H_
    #define MY_H_
    int obtain_c(char *str, va_list list);
    int obtain_u(char *str, va_list list);
    int obtain_s(char *str, va_list list);
    int obtain_d_i(char *str, va_list list);
    int obtain_percent(char *str, va_list list);
    int obtain_o(char *str, va_list list);
    int obtain_x(char *str, va_list list);
    int obtain_x_maj(char *str, va_list list);
    int obtain_f(char *str, va_list list);
    int obtain_b(char *str, va_list list);
    int obtain_e(char *str, va_list list);
    int obtain_p(char *str, va_list list);
    int obtain_g(char *str, va_list list);
    char *obtain_f_sub(int argument_hatag, int precision, double nb);
    char *obtain_e_sub(int precision, int argument_hatag, double nb);
    char *decimal_to_other_base(unsigned int nbr, int nb_base);
    int my_compute_power_rec(int nb, int p);
    char *my_revstr(char *str);
    int my_strlen(char const *str);
    void print_char(char c);
    int print_int(int nb);
    int print_string(char const * str);
    unsigned int print_unsigned_int(unsigned int nb);
    int my_printf(char const *format, ...);
    char *my_strlowcase(char *str);
    int round_nb(double save_nb, char *string_nb);
    void concatenate(char *result, char *unit, char *decimal);
    void concatenate_result(char *result, char *result_sub,\
    int *negatif_point, int count_unit_lenght);
    void concatenate_e(char *result, char unit, char *decimal);
    int find_count_unit_lenght(int nb);
    void concatenate_result_e(char *str, char *result_sub,\
    int *negatif_point_addnb, int count_unit_lenght);
    int get_p(double *nb);
    int put_nb_expo(char *result, int p, int i);
    int *obtain_precision(char const *str, int *bat);
    int add_space_e(int len, int *bat, char *string);
    int add_space_f(int len, int *bat, char *string);
    char *case_0(void);
#endif /* !MY_H_ */
