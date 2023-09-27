/*
** EPITECH PROJECT, 2022
** my_compute_power_rec
** File description:
** ecursive function that returns power
*/

int my_compute_power_rec(int nb, int p)
{
    if (p == 0){
        return 1;
    }
    if (p == 1){
        return nb;
    }
    if (p < 0){
        return 0;
    }
    long int test = nb * my_compute_power_rec(nb, p - 1);
    if ((test * nb) > 2147483647){
        return 0;
    }
    return test;
}
