/*
** EPITECH PROJECT, 2022
** B-CPE-101-BDX-1-1-myprintf-tom.mendy
** File description:
** print_char
*/

#include <unistd.h>

void print_char(char c)
{
    write(1, &c, 1);
}
