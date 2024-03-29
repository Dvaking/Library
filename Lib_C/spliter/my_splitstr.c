/*
** EPITECH PROJECT, 2023
** Lib
** File description:
** my_splitstr
*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

static int count_word(char const *str, int separator)
{
    int nbr_word = 0;
    int word = 0;

    if (!str)
        return -1;
    for (int i = 0; str[i] != '\0'; i += 1){
        if (word == 0 && separator != str[i]){
            word = 1;
            nbr_word += 1;
        }
        if (separator == str[i])
            word = 0;
    }
    return nbr_word;
}

static char *malloc_and_create_str(char const *str, int pos, int j)
{
    char *word = malloc(sizeof(char) * (j + 1));

    if (!str || !word)
        return NULL;
    for (int move = 0; move < j; move += 1)
        word[move] = str[pos + move];
    word[j] = '\0';
    return word;
}

static char *add_value_in_tab(char const *str, int *pos, int separator)
{
    int j = 0;
    char *word = 0;

    if (!pos || !str)
        return NULL;
    while (str[*pos] != '\0' && separator == str[*pos])
        *pos += 1;
    while (str[*pos + j] != '\0' && separator != str[*pos + j])
        j += 1;
    word = malloc_and_create_str(str, *pos, j);
    if (word == NULL)
        return NULL;
    *pos += j;
    return word;
}

char **my_splitstr(char const *str, int separator)
{
    int word = 0;
    int nbr_word = 0;
    char **tab = NULL;

    if (str == NULL)
        return NULL;
    nbr_word = count_word(str, separator);
    if (nbr_word == -1)
        return NULL;
    tab = malloc(sizeof(char *) * (nbr_word + 1));
    if (tab == NULL)
        return NULL;
    for (int pos = 0; word < nbr_word; word += 1){
        tab[word] = add_value_in_tab(str, &pos, separator);
        if (tab[word] == NULL)
            return NULL;
    }
    tab[nbr_word] = NULL;
    return tab;
}
