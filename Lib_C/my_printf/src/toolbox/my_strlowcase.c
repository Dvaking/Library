/*
** EPITECH PROJECT, 2022
** B-CPE-101-BDX-1-1-myprintf-tom.mendy
** File description:
** my_strlowcase
*/

char *my_strlowcase(char *str)
{
    for (int i = 0; str[i] != '\0'; i += 1){
        if (str[i] >= 'A' && str[i] <= 'Z'){
            str[i] = str[i] + 32;
        }
    }
    return str;
}
