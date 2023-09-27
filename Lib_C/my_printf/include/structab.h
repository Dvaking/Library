/*
** EPITECH PROJECT, 2022
** structab
** File description:
** tab de structure
*/
#include <stdarg.h>

#ifndef STRUCTAB_H_
    #define STRUCTAB_H_
    struct tab {
        char c;
        int (*flags)(char *, va_list);
    };

#endif /* !STRUCTAB_H_ */
