/*
** EPITECH PROJECT, 2022
** B-CPE-101-BDX-1-1-myprintf-tom.mendy
** File description:
** test_my_printf
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

void redirect_all_std(void) {
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_printf, simple_string, .init = redirect_all_std) {
    my_printf("hello world");
    cr_assert_stdout_eq_str("hello world");
}

Test(my_printf, unique_int_flag, .init = redirect_all_std) {
    my_printf("%d", 52);
    cr_assert_stdout_eq_str("52");
}

Test(my_printf, unique_null_int_flag, .init = redirect_all_std) {
    my_printf("%d", 0);
    cr_assert_stdout_eq_str("0");
}

Test(my_printf, unique_negative_int_flag, .init = redirect_all_std) {
    my_printf("%d", -52);
    cr_assert_stdout_eq_str("-52");
}

Test(my_printf, unique_octa_flag, .init = redirect_all_std) {
    my_printf("%o", 8);
    cr_assert_stdout_eq_str("10");
}

Test(my_printf, unique_hexa_flag, .init = redirect_all_std) {
    my_printf("%x", 16);
    cr_assert_stdout_eq_str("10");
}

Test(my_printf, unique_hexa_2_flag, .init = redirect_all_std) {
    my_printf("%x", 123456);
    cr_assert_stdout_eq_str("1e240");
}

Test(my_printf, unique_hexa_maj_flag, .init = redirect_all_std) {
    my_printf("%X", 16);
    cr_assert_stdout_eq_str("10");
}

Test(my_printf, unique_hexa_maj_2_flag, .init = redirect_all_std) {
    my_printf("%X", 123456);
    cr_assert_stdout_eq_str("1E240");
}

Test(my_printf, unique_binarary_flag, .init = redirect_all_std) {
    my_printf("%b", 2);
    cr_assert_stdout_eq_str("10");
}

Test(my_printf, unique_unsingned_flag, .init = redirect_all_std) {
    my_printf("%u", 2);
    cr_assert_stdout_eq_str("2");
}

Test(my_printf, unique_unsingned_2_flag, .init = redirect_all_std) {
    my_printf("%u", -2);
    cr_assert_stdout_eq_str("4294967294");
}

Test(my_printf, unique_double_flag, .init = redirect_all_std) {
    my_printf("%f", 52.0);
    cr_assert_stdout_eq_str("52.000000");
}

Test(my_printf, unique_double_2_flag, .init = redirect_all_std) {
    my_printf("%f", 0.1);
    cr_assert_stdout_eq_str("0.100000");
}

Test(my_printf, unique_double_round_flag, .init = redirect_all_std) {
    my_printf("%f", 0.9999999);
    cr_assert_stdout_eq_str("1.000000");
}

Test(my_printf, unique_double_round_2_flag, .init = redirect_all_std) {
    my_printf("%f", 9.9999999);
    cr_assert_stdout_eq_str("10.000000");
}

Test(my_printf, unique_double_negatif_flag, .init = redirect_all_std) {
    my_printf("%f", -52.0);
    cr_assert_stdout_eq_str("-52.000000");
}

Test(my_printf, unique_double_negatif_2_flag, .init = redirect_all_std) {
    my_printf("%f", -0.1);
    cr_assert_stdout_eq_str("-0.100000");
}

Test(my_printf, unique_double_negatif_round_flag, .init = redirect_all_std) {
    my_printf("%f", -0.9999999);
    cr_assert_stdout_eq_str("-1.000000");
}

Test(my_printf, unique_double_science_flag, .init = redirect_all_std) {
    my_printf("%e", 52.0);
    cr_assert_stdout_eq_str("5.200000e+01");
}

Test(my_printf, unique_double_science_negative_flag, .init = redirect_all_std){
    my_printf("%e", -52.0);
    cr_assert_stdout_eq_str("-5.200000e+01");
}

Test(my_printf, unique_double_science_2_flag, .init = redirect_all_std) {
    my_printf("%e", 5284358792375.0);
    cr_assert_stdout_eq_str("5.284359e+12");
}

Test(my_printf, unique_double_science_3_flag, .init = redirect_all_std) {
    my_printf("%e", 0.000000000000000009);
    cr_assert_stdout_eq_str("9.000000e-18");
}

Test(my_printf, unique_double_science_round_flag, .init = redirect_all_std) {
    my_printf("%e", 9.9999991);
    cr_assert_stdout_eq_str("9.999999e+00");
}

Test(my_printf, unique_double_science_round_2_flag, .init = redirect_all_std) {
    my_printf("%e", 9.9999999);
    cr_assert_stdout_eq_str("1.000000e+01");
}

Test(my_printf, unique_double_science_round_3_flag, .init = redirect_all_std) {
    my_printf("%e", 0.0);
    cr_assert_stdout_eq_str("0.000000e+00");
}

Test(my_printf, unique_double_g_flag, .init = redirect_all_std) {
    my_printf("%g", 1234.46);
    cr_assert_stdout_eq_str("1234.46");
}

Test(my_printf, unique_double_g_2_flag, .init = redirect_all_std) {
    my_printf("%g", 1234567890.0);
    cr_assert_stdout_eq_str("1.23457e+09");
}

Test(my_printf, unique_char_flag, .init = redirect_all_std) {
    my_printf("%c", 'a');
    cr_assert_stdout_eq_str("a");
}

Test(my_printf, unique_string_flag, .init = redirect_all_std) {
    my_printf("%s", "hello");
    cr_assert_stdout_eq_str("hello");
}

Test(my_printf, unique_pourcentage_flag, .init = redirect_all_std) {
    my_printf("%%");
    cr_assert_stdout_eq_str("%");
}

Test(my_printf, unique_fasle_flag, .init = redirect_all_std) {
    my_printf("%r");
    cr_assert_stdout_eq_str("%r");
}

Test(my_printf, unique_backslash_n, .init = redirect_all_std) {
    my_printf("\n");
    cr_assert_stdout_eq_str("\n");
}

Test(my_printf, texte_plus_int_flag, .init = redirect_all_std) {
    my_printf("Hello %d", 52);
    cr_assert_stdout_eq_str("Hello 52");
}

Test(my_printf, texte_plus_null_int_flag, .init = redirect_all_std) {
    my_printf("Hello %d", 0);
    cr_assert_stdout_eq_str("Hello 0");
}

Test(my_printf, texte_plus_negative_int_flag, .init = redirect_all_std) {
    my_printf("Hello %d", -52);
    cr_assert_stdout_eq_str("Hello -52");
}

Test(my_printf, texte_plus_char_flag, .init = redirect_all_std) {
    my_printf("Hello %c", 'a');
    cr_assert_stdout_eq_str("Hello a");
}

Test(my_printf, texte_plus_string_flag, .init = redirect_all_std) {
    my_printf("Hello %s", "hello");
    cr_assert_stdout_eq_str("Hello hello");
}

Test(my_printf, texte_plus_pourcentage_flag, .init = redirect_all_std) {
    my_printf("Hello %%");
    cr_assert_stdout_eq_str("Hello %");
}

Test(my_printf, texte_plus_fasle_flag, .init = redirect_all_std) {
    my_printf("Hello %r");
    cr_assert_stdout_eq_str("Hello %r");
}

Test(my_compute_power_rec, my_compute_power_rec_1) {
    cr_assert_eq(my_compute_power_rec(10, 0),1);
}

Test(my_compute_power_rec, my_compute_power_rec_2) {
    cr_assert_eq(my_compute_power_rec(10, -1),0);
}

Test(my_compute_power_rec, my_compute_power_rec_3) {
    cr_assert_eq(my_compute_power_rec(10, 1000),0);
}

Test(my_strlowcase, my_strlowcase) {
    char str[] = "ABr";
    cr_assert_str_eq(my_strlowcase(str),"abr");
}

Test(decimal_to_other_base, decimal_to_other_base) {
    char str[] = "ABr";
    cr_assert_str_eq(my_strlowcase(str),"abr");
}

Test(my_printf, unique_int_precision_flag, .init = redirect_all_std) {
    my_printf("%6.3d", 52);
    cr_assert_stdout_eq_str("   052");
}

Test(my_printf, unique_octa_precision_flag, .init = redirect_all_std) {
    my_printf("%6.3o", 8);
    cr_assert_stdout_eq_str("   010");
}

Test(my_printf, unique_hexa_precision_flag, .init = redirect_all_std) {
    my_printf("%6.3x", 16);
    cr_assert_stdout_eq_str("   010");
}

Test(my_printf, unique_binary_precision_flag, .init = redirect_all_std) {
    my_printf("%6.3b", 2);
    cr_assert_stdout_eq_str("   010");
}

Test(my_printf, unique_f_precision_flag, .init = redirect_all_std) {
    my_printf("%10.3f", 12.34);
    cr_assert_stdout_eq_str("    12.340");
}

Test(my_printf, unique_hf_precision_flag, .init = redirect_all_std) {
    my_printf("%#6.0f", 12.34);
    cr_assert_stdout_eq_str("   12.");
}

Test(my_printf, unique_e_precision_flag, .init = redirect_all_std) {
    my_printf("%10.3e", 12.34);
    cr_assert_stdout_eq_str(" 1.234e+01");
}

Test(my_printf, unique_he_precision_flag, .init = redirect_all_std) {
    my_printf("%#10.3e", 12.34);
    cr_assert_stdout_eq_str(" 1.234e+01");
}

Test(my_printf, unique_hHe_precision_flag, .init = redirect_all_std) {
    my_printf("%e", 12.9999999);
    cr_assert_stdout_eq_str("1.300000e+01");
}

Test(my_printf, unique_uu_precision_flag, .init = redirect_all_std) {
    my_printf("%10.3u", 12);
    cr_assert_stdout_eq_str("       012");
}

Test(my_printf, unique_muu_precision_flag, .init = redirect_all_std) {
    my_printf("%12u", -12);
    cr_assert_stdout_eq_str("  4294967284");
}