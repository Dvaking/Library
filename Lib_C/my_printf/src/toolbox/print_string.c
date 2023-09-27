/*
** EPITECH PROJECT, 2022
** B-CPE-101-BDX-1-1-myprintf-tom.mendy
** File description:
** print_string
*/

#include <stdlib.h>

int my_strlen(char const *str);
void print_char(char c);

int print_string(char *str)
{
    int i = 0;
    while (str[i] != '\0'){
        print_char(str[i]);
        i += 1;
    }
    int len = my_strlen(str);
    free(str);
    return len;
}
